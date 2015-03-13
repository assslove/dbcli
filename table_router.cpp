/*
 * =====================================================================================
 *
 *       Filename:  table_router.cpp
 *
 *    Description:  提供对分库分分表的操作
 *
 *        Version:  1.0
 *        Created:  2015年01月31日 11时46分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	houbin , houbin-12@163.com
 *   Organization:  Houbin, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdio.h>

#include "mysql_cli.h"
#include "table_router.h"

TableRouter::TableRouter(MysqlCli *mc_, const char* db_prename_, const char* tb_prename_,\
		uint32_t db_count_, uint32_t tb_count_) : Table(mc_, db_prename_, tb_prename_)
{
	strcpy(m_db_prename, db_prename_);
	strcpy(m_tb_prename, tb_prename_);
	m_db_count = db_count_;
	m_tb_count = tb_count_;
}

char* TableRouter::getTableName(uint32_t id)
{
	this->m_id = id;
	int len;

	switch (m_db_count) {
		case 100:
			len = sprintf(this->m_dbname, "%s_%02d", m_db_prename, id % 100);
			this->m_dbname[len] = '\0';
			break;
		default:
			len = sprintf(this->m_dbname, "%s", m_db_prename);
			this->m_dbname[len] = '\0';
			break;
	}

	this->m_mc->mysqlSelectDB(this->m_dbname);

	//生成表名
	switch (m_tb_count) {
		case 10:
			len = sprintf(this->m_db_tb_name, "%s.%s_%d", m_dbname, m_tb_prename, id / 100 % 10);
			this->m_db_tb_name[len] = '\0';
			break;
		case 100:
			len = sprintf(this->m_db_tb_name, "%s.%s_%02d", m_dbname, m_tb_prename, id / 100 % 100);
			this->m_db_tb_name[len] = '\0';
			break;
		default:
			len = sprintf(this->m_db_tb_name, "%s.%s", m_dbname, m_tb_prename);
			this->m_db_tb_name[len] = '\0';
			break;
	}

	return this->m_db_tb_name;
}
