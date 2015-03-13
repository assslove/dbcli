/*
 * =====================================================================================
 *
 *       Filename:  用户表
 *
 *    Description:  用来测试对数据库的访问
 *
 *        Version:  1.0
 *        Created:  2015年02月02日 11时32分36秒
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

#include "user.h"
#include "proto/lib/user.pb.h"

using namespace db_proto;

User::User(MysqlCli *mc_) : TableRouter(mc_, "TEST", "t_user", 1, 1)
{
	
}

int User::getUser()
{
	GENSQL("select * from %s where user_id=%u", this->getTableName(1000), 3000);
	DEBUG(0, "%s, %u", this->m_sqlstr, this->m_sqllen);
	MUser user;
	QUERY_ONE_BEGIN(1) 
		user.set_userid(INT_NEXT_COL);
		user.set_name(NEXT_COL);
		user.set_score(INT_NEXT_COL);

		int i = 0;
		STR_NEXT_COL(&i, sizeof(i));
		DEBUG(0, "%u,%s,%u, %u", user.userid(), user.name().c_str(), user.score(), i);
	QUERY_ONE_END()
}

void User::insertUser()
{
	char attr[10] = {'\0'};
	int i = 5;
	memcpy(attr, &i, sizeof(i));
	GENSQL("insert into %s values(%u, '%s', %u, '%s')", this->getTableName(3000), 3000, "笑纳", 20, attr);
	if (int ret = this->execInsertSql(1)) {
		ERROR(0, "cannot insert %u", ret);
	}
}

void User::updateUser()
{
	GENSQL("update %s set score=%u", this->getTableName(2000), 1);
	if (int ret = this->execUpdateSql()) {
		ERROR(0, "cannot update %u", ret);
	}
}

void User::deleteUser()
{
	GENSQL("delete from %s where user_id=%u", this->getTableName(2000), 2000);
	if (int ret = this->execDeleteSql(2)) {
		ERROR(0, "cannot update %u", ret);
	}
}
