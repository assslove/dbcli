#ifndef _LIMIT_H
#define _LIMIT_H

#include <dbcli/table_router.h>

#include "proto/lib/limit.pb.h"

using namespace db_proto;

class Limit : public TableRouter 
{
	public:
		Limit(MysqlCli *mc_);
		~Limit() {}
	public:
		int getLimit(MLimitlist *list);
		void updateLimit();
		void delLimit();
		void insertLimit();
};

#endif
