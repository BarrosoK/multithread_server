#include <iostream>
#include <netdb.h>
#include "Server.h"
#include "SendablePacket.h"
#include "ReceivablePacket.h"
#include "src/util/Time.h"
#include "src/util/LoggerFile.h"
#include "Event.h"
#include "src/events/Announcement.h"

#include <mysql.h>
#include <mysql++.h>
#include <DatabasePool.h>
#include <QtWidgets/QApplication>
#include <QtCore/QStringListModel>
#include "ui/ServerUi.h"

void client_test(int ac, char **av);

void test()
{
	mysqlpp::StoreQueryResult sq = DatabasePool::getInstance()->selectFromTable("accounts");
	mysqlpp::StoreQueryResult::iterator it;
	it = sq.begin();
	while (it != sq.end()) {
		mysqlpp::Row row = *it;
		std::cout << row[1] << " " << row[2] << std::endl;
		it++;
	}
}


void createUi(int ac, char **av) {
	QApplication app(ac, av);
	ServerUI::getInstance()->show();
	app.exec();
}

int main(int ac, char **av)
{
	/* DBPOOL TEST
	for (int i = 0; i < 100; i++) {
		new std::thread(test);
	}
	*/

	if (ac > 1) {
		client_test(ac, av);
		return 0;
	} else {
		new std::thread(createUi, ac, av);
	}
	Server::logger.write("logger test", "  ", 42);
	Server *server = new Server(4242);
	server->init(true);
	return 0;
}

