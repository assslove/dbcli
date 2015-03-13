/*
 * =====================================================================================
 *
 *       Filename:  mysql_cli.cpp
 *
 *    Description:  Mysql客户端封装
 *					名称尽量与mysqlcli保持一致，只是写法不同，加上出错日志处理
 *					使用MYSQL函数需要去引用该类
 *        Version:  1.0
 *        Created:  2015年01月27日 23时10分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	houbin , houbin-12@163.com
 *   Organization:  XiaoNan, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#include <string.h>
#include <errmsg.h>

#include "dbcli_def.h"
#include "mysql_cli.h"

MysqlCli::MysqlCli(const char *host_, const char *user_, const char *passwd_, uint16_t port_, const char* charset_)
{
	strcpy(m_host, host_);		
	strcpy(m_user, user_);
	strcpy(m_passwd, passwd_);
	m_port = port_;
	
	if (charset_) {
		strcpy(m_charset, charset_);
	} else {
		strcpy(m_charset, "utf8");
	}
}

MysqlCli::~MysqlCli()
{
	if (m_mysql) {
		mysql_close(m_mysql);		
	}

	mysql_library_end();
}

int MysqlCli::mysqlInit()		
{
	if (mysql_library_init(0, NULL, NULL)) {
		ERROR(m_id, "could not init MySQL lib");
		return -1;
	}

	m_mysql = mysql_init(NULL);
	if (!m_mysql) {
		ERROR(m_id, "mysql init error");
		return -1;
	}

	return mysqlConnect();
}

int MysqlCli::mysqlExecQuery(const char *sqlstr_, int sqllen_, MYSQL_RES **res_)
{
	if (!this->mysqlExec(sqlstr_, sqllen_)) {
		if (!(*res_ = mysql_store_result(m_mysql))) {
			ERROR(m_id, "store result failed[%s][%s]", sqlstr_, mysql_error(m_mysql));
			return DB_ERR_STORE_RES;
		}
	} else {
		return DB_ERR;	
	}

	return 0;
}

int MysqlCli::mysqlExecUpdate(const char *sqlstr_, int sqllen_, int* affectRows_)
{
	if (!this->mysqlExec(sqlstr_, sqllen_)) {
		*affectRows_ = mysql_affected_rows(m_mysql);
	} else {
		return DB_ERR;	
	}

	return 0;	
}

int MysqlCli::mysqlConnect()
{
	m_mysql = mysql_real_connect(m_mysql, m_host, m_user, m_passwd, NULL, m_port, NULL, 0);
	if (!m_mysql) {
		ERROR(m_id, "cannot not connect mysql [host=%s,user=%s,passwd=%s,port=%u]", m_host, m_user, m_passwd, m_port);
		return -1;
	}

	if (mysql_set_character_set(m_mysql, m_charset)) {
		ERROR(m_id, "mysql set character set failed [%s]", mysql_error(m_mysql));
		return -1;
	}

	return 0;
}

int MysqlCli::mysqlExec(const char *sqlstr_, int sqllen_)
{
#ifdef ENABLE_SQL
	INFO(0, "SQL:%s", sqlstr_);
#endif

	m_ret = mysql_real_query(m_mysql, sqlstr_, sqllen_);
	if (!m_ret) {
		return 0;
	}

	if (mysql_errno(m_mysql) == CR_SERVER_GONE_ERROR) { //会话关闭
		if (this->mysqlConnect() == 0) { //连接成功再次执行
			return mysql_real_query(m_mysql, sqlstr_, sqllen_); 
		} else { //否则返回错误码
			return mysql_errno(m_mysql);
		}
	} else {
		ERROR(m_id, "mysql exec failed [%s][%s]", sqlstr_, mysql_error(m_mysql));
		return m_ret;
	}

	return 0;
}
