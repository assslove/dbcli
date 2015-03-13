#ifndef _TABLE_ROUTER_H
#define _TABLE_ROUTER_H

#include "table.h"

class TableRouter : public Table {

	public:

		/* @brief 构造函数
		 * @param mc_
		 * @param db_prename_ db名字
		 * @param tb_prename_ table 名字
		 * @param db_count_ db的个数
		 * @param tb_count_ table的个数
		 */
		TableRouter(MysqlCli *mc_, const char* db_prename_, const char* tb_prename_, uint32_t db_count_, uint32_t tb_count_);

		/* @brief 获得表名
		 */
		virtual char* getTableName(uint32_t id_);

		/* @brief 析构
		 */
		virtual ~TableRouter() {}

	protected:
		char m_db_prename[32];  //库前缀
		char m_tb_prename[32]; //表名
		uint32_t m_db_count;   //库个数 
		uint32_t m_tb_count;   //表个数
		
};

#endif
