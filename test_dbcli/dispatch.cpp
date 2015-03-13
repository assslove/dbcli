/*
 * =====================================================================================
 *
 *       Filename:  dispatch.cpp
 *
 *    Description:  数据库处理入口
 *
 *        Version:  1.0
 *        Created:  2015年02月02日 17时15分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:	houbin , houbin-12@163.com
 *   Organization:  Houbin, Inc. ShangHai CN. All rights reserved.
 *
 * =====================================================================================
 */

#include <dbcli/mysql_cli.h>

#include "dispatch.h"

Dispatch::Dispatch(MysqlCli *mc_) 
{
	m_mc = mc_;
	m_user = new User(m_mc);
	m_limit = new Limit(m_mc);
}

Dispatch::~Dispatch() 
{
	delete m_user;
	m_user = NULL;

	delete m_limit;
	m_limit = NULL;

	delete m_mc;
	m_mc = NULL;
}
