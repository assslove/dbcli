/*
 * =====================================================================================
 *
 *       Filename:  limit.cpp
 *
 *    Description:  limit 数据库操作
 *
 *        Version:  1.0
 *        Created:  2015年02月02日 16时50分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	houbin , houbin-12@163.com
 *   Organization:  Houbin, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#include <dbcli/mysql_cli.h>
#include <dbcli/table_router.h>
#include <dbcli/dbcli_def.h>

#include "limit.h"


Limit::Limit(MysqlCli *mc_) : TableRouter(mc_, "TEST", "t_limit", 1, 1)
{
}

int Limit::getLimit(MLimitlist *list)
{
	GENSQL("select type, value from %s where user_id=%u", this->getTableName(1000), 1000);
	DEBUG(0, "%s, %u, %u", this->m_sqlstr, this->m_sqllen, strlen(this->m_sqlstr));
	//拷贝列表	
	QUERY_MULTI_BEGIN() 
		MLimit *limit = list->add_limit();
		limit->set_type(INT_NEXT_COL);
		limit->set_value(INT_NEXT_COL);
	QUERY_MULTI_END()
}

void Limit::updateLimit()
{

}

void Limit::delLimit()
{

}

void Limit::insertLimit()
{

}
