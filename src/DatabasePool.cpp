/*
 * Author: pedrito.
 * Date: 06/08/19
 */

#include <DatabasePool.h>

#include "DatabasePool.h"

DatabasePool::DatabasePool()
{
}

DatabasePool::~DatabasePool()
{
	clear();
}

mysqlpp::Connection *DatabasePool::create()
{

	return new mysqlpp::Connection(DATABASE, HOST, USER, PASS);
}

void DatabasePool::destroy(mysqlpp::Connection *connection)
{
	delete connection;
}

unsigned int DatabasePool::max_idle_time()
{
	return 5;
}

mysqlpp::Connection DatabasePool::getConnection()
{
	mysqlpp::Connection *conn = NULL;
	try {
		conn = this->grab();
		if (!conn) {
			throw "Failed to get a connection from the pool!";
		}
	} catch (mysqlpp::Exception &e) {
		std::cout << e.what() << std::endl;
	} catch (std::string &e) {
		std::cout << e << std::endl;
	}
	return conn;
}


void DatabasePool::close(mysqlpp::Connection *conn)
{
	this->release(conn);
}

mysqlpp::StoreQueryResult DatabasePool::selectFromTable(std::string table, std::string columns)
{
	mysqlpp::Connection *con;
	mysqlpp::StoreQueryResult sq = {};
	try {
		con = grab();
		std::string s = "SELECT " + columns + " FROM " + table;
		mysqlpp::Query q = con->query(s);
		sq = q.store();
	} catch (mysqlpp::Exception &e) {
		std::cout << e.what() << std::endl;
	}
	close(con);
	return sq;
}

mysqlpp::StoreQueryResult DatabasePool::selectFromTable(std::string table,  std::string where, std::string columns)
{
	mysqlpp::Connection *con;
	mysqlpp::StoreQueryResult sq = {};
	try {
		con = grab();
		std::string s = "SELECT " + columns + " FROM " + table + " WHERE " + where;
		mysqlpp::Query q = con->query(s);
		sq = q.store();
	} catch (mysqlpp::Exception &e) {
		std::cout << e.what() << std::endl;
	}
	close(con);
	return sq;
}
