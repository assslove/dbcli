#ifndef _USER_H
#define _USER_H

#include <dbcli/table_router.h>

class User : public TableRouter
{
	public:
		User(MysqlCli *mc_);
		~User() {}

	public:
		int getUser();
		void insertUser();
		void updateUser();
		void deleteUser();
};

#endif
