#ifndef _TABLE_H
#define _TABLE_H

#include <stdint.h>
#include <mysql.h>

class MysqlCli;

#define SQLSTR_LEN 1024 * 10

/* @brief 应用程序基类 提供对表的基本操作
 */
class Table {

	public:

		/* @brief 构造函数
		 */
		Table(MysqlCli *mc_, const char* dbname_, const char* tbname_);

		/* @brief 执行查询语句
		 * @param res_ 执行的结果集
		 * @param count_ 影响的行数
		 */
		int execQuerySql(MYSQL_RES **res_, uint32_t *count_); 

		/*  @brief 执行更新语句
		 *  @param affectRows_为影响的行数
		 */
		int execUpdateSql();

		/* @brief 执行插入语句
		 * @param duplicate_ 为找到指定记录的错误
		 */
		int execInsertSql(int duplicate_);

		/* @brief 执行删除语句
		 * @param nofind_ 为找不到指定记录的错误
		 */
		int execDeleteSql(int nofind_);

		/* @brief 执行插入语句并且返回最后一次执行的主键自增id
		 * @param duplicate_ 相同主键错误
		 * @param lastid_ 最后一次id
		 */
		int execInsertSqlAndGetLastId(int duplicate_, uint32_t *lastid_);

		/* @brief 返回指定数据库的全表名 如XX_00.xx_00;
		 */
		virtual char* getTableName(uint32_t id);

		/* @brief 析构函数
		 */
		virtual ~Table() {}
		
	public:
		MysqlCli *m_mc; //底层数据库类

	protected:
		char m_sqlstr[SQLSTR_LEN];	//最大查询语句长度
		int m_sqllen;				//sql语句长度
		MYSQL_RES *m_res;			//中间变量
		MYSQL_ROW m_row;			//中间变量
		char m_dbname[32];			//db名字
		char m_tbname[32];			//table名字
		char m_db_tb_name[32];		//db_XX.tb_XX名字
		uint32_t m_id;				//主键id
		int m_affectedrows;
		int m_ret;
};

#endif
