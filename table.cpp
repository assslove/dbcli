/*
 * =====================================================================================
 *
 *       Filename:  db_name.cpp
 *
 *    Description:  对库名表名的封装, 针对分表分库用
 *
 *        Version:  1.0
 *        Created:  2015年01月27日 23时16分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	houbin , houbin-12@163.com
 *   Organization:  XiaoNan, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#include <string.h>
#include <mysqld_error.h>

#include "mysql_cli.h"
#include "dbcli_def.h"
#include "table.h"

Table::Table(MysqlCli *mc_, const char* dbname_, const char* tbname_)
{
	this->m_mc = mc_;	
	strcpy(m_dbname, dbname_);
	strcpy(m_tbname, tbname_);
	m_res = NULL;
	memset(m_sqlstr, 0, sizeof(m_sqlstr));
	m_sqllen = 0;
	m_id = 0;
	m_affectedrows = 0;
	m_ret = 0;
}

int Table::execUpdateSql()
{
	return this->m_mc->mysqlExecUpdate(m_sqlstr, m_sqllen, &m_affectedrows);
}

int Table::execInsertSql(int duplicate_)
{
	this->m_mc->mysqlSetId(m_id);
	if ((m_ret = this->m_mc->mysqlExecUpdate(m_sqlstr, m_sqllen, &m_affectedrows)) == 0) {
		return 0;
	} else if (m_ret == ER_DUP_ENTRY) { //主键重复返回错误码
		return duplicate_;
	} 

	return m_ret;
}

int Table::execDeleteSql(int nofind_)
{
	this->m_mc->mysqlSetId(m_id);
	if ((m_ret = this->m_mc->mysqlExecUpdate(m_sqlstr, m_sqllen, &m_affectedrows)) == 0) {
		if (m_affectedrows == 0) { //没有删除指定的行 说明找不到
			return nofind_;
		} else {
			return 0;
		}
	} 

	return m_ret;
}

int Table::execInsertSqlAndGetLastId(int duplicate_, uint32_t *lastid_)
{
	this->m_mc->mysqlSetId(m_id);
	if ((m_ret = this->m_mc->mysqlExecUpdate(m_sqlstr, m_sqllen, &m_affectedrows)) == 0) {
		*lastid_ = this->m_mc->mysqlGetLastId();
		return 0;
	} else if (m_ret == ER_DUP_ENTRY) {
		return duplicate_;
	}

	return m_ret;
}

char* Table::getTableName(uint32_t id_)
{
	this->m_id = id_;
	this->m_mc->mysqlSelectDB(this->m_dbname);	
	sprintf(this->m_db_tb_name, "%s.%s", this->m_dbname, this->m_tbname);
	return this->m_db_tb_name;
}

int Table::execQuerySql(MYSQL_RES **res_, uint32_t *count_) 
{
	this->m_mc->mysqlSetId(m_id);
	if ((m_ret = this->m_mc->mysqlExecQuery(m_sqlstr, m_sqllen, res_))) {
		return m_ret;
	} else {
		*count_ = this->m_mc->mysqlGetAffectedRows(*res_);
		return 0;
	}
}	
