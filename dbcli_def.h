#ifndef _DBCLI_DEF_H
#define _DBCLI_DEF_H

#include <stdlib.h>
#include <stdint.h>
#include <mysql.h>

/* @brief 错误码内部定义 1-1000 预留，应用程序不可使用
 */
enum DB_ERROR_CODE {
	DB_SUCC = 0,			//成功	
	DB_ERR = 1,				//统一错误
	DB_ERR_STORE_RES = 2,	//存储结果失败
};

/* @brief str to int
 */
inline int safe_atoi(const char *str) 
{
	return (str != NULL) ? atoi(str) : 0;
}

/* @brief str to uint64_t
 */
inline uint64_t safe_atol(const char *str) 
{
	return (str != NULL) ? atoll(str) : 0;
}

//开始单个查询开始
#define QUERY_ONE_BEGIN(nofind_err)  \
	uint32_t  count, ret;\
	ret = this->execQuerySql(&m_res, &count);\
	if (ret == 0) {\
		if (count != 1) {\
			mysql_free_result(m_res);\
			DEBUG(0, "no record exist [%u]", nofind_err);\
			return nofind_err;\
		} else { \
			m_row = mysql_fetch_row(m_res);	\
			int idx_ = -1;

//开始单个查询结束
#define QUERY_ONE_END() \
			mysql_free_result(m_res); \
			return 0;\
		}\
	} else {\
		return DB_ERR; \
	}

//下一行
#define  NEXT_COL	(m_row[++idx_])

//cpy int 
#define INT_NEXT_COL  safe_atoi(NEXT_COL)

//cpy int64
#define INT64_NEXT_COL  safe_atol(NEXT_COL)

//拷贝字符串 二进制
#define STR_NEXT_COL(val, max) \
	++idx_;\
	mysql_fetch_lengths(m_res); \
	if (m_res->lengths[idx_] < max) {\
		memcpy(val, m_row[idx_], m_res->lengths[idx_]);\
	} else {\
		memcpy(val, m_row[idx_], max);\
	}
	
//开始循环接收数据 protobuf
//type指类型 msg 指protobuf msg, field指msg中的项 指带结构体的类型，
//如果是普通类型见QUERY_MULTI_NORMAL_BEGIN
#define QUERY_MULTI_BEGIN()  \
	uint32_t count, ret;\
	ret = this->execQuerySql(&m_res, &count);\
	if (ret == 0) {\
		while (m_row = mysql_fetch_row(m_res)) {\
			int idx_ = -1;

//结束循环接收数据
#define QUERY_MULTI_END()\
		}\
		mysql_free_result(m_res);\
		return 0;\
	} else {\
		return DB_ERR;\
	}

#define GENSQL(fmt, arg...) this->m_sqllen = sprintf(this->m_sqlstr, fmt, ##arg), this->m_sqlstr[this->m_sqllen] = '\0';


#define MYSQL_REAL_ESCAPE_STRING(to, from, len) this->m_mc->mysqlRealEscapeString(to, from, len);
#endif
