/*
 * Author: pedrito.
 * Date: 06/08/19
 */

#ifndef SERVER_DATABASEPOOL_H
#define SERVER_DATABASEPOOL_H

#include <mysql++.h>
#include "Singleton.h"

#define DATABASE "game"
#define USER "pedrito"
#define PASS "root"
#define HOST "localhost"

class DatabasePool : public Singleton<DatabasePool>, public mysqlpp::ConnectionPool {
		friend class Singleton<DatabasePool>;
	private:
		DatabasePool();
		~DatabasePool();
	protected:
		mysqlpp::Connection *create() override;
		void destroy(mysqlpp::Connection *connection) override;
		unsigned int max_idle_time() override;
	public:
		mysqlpp::Connection getConnection();
		void close(mysqlpp::Connection *con);
		mysqlpp::StoreQueryResult selectFromTable(std::string table, std::string columns = "*");
		mysqlpp::StoreQueryResult selectFromTable(std::string table, std::string where, std::string columns);
};

#endif //SERVER_DATABASEPOOL_H
