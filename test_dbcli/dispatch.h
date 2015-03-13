#ifndef _DISPATCH_H
#define _DISPATCH_H

#include <stdlib.h>

#include "user.h"
#include "limit.h"

class MysqlCli;

class Dispatch 
{
	public: 
		Dispatch(MysqlCli *mc_);
		~Dispatch();

	public:
		User* m_user;
		Limit* m_limit;

	private:
		MysqlCli *m_mc;
};

#endif
