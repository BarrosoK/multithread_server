#include <iostream>
#include <netdb.h>
#include "Server.h"
#include "SendablePacket.h"
#include "ReceivablePacket.h"
#include "src/util/Time.h"
#include "src/util/LoggerFile.h"
#include "Event.h"
#include "src/events/Announcement.h"


void client_test(int ac, char **av);


int main(int ac, char **av)
{
	if (ac > 1) {
		client_test(ac, av);
		return 0;
	}
	Server::logger.write("logger test", "  ", 42);
	Server *server = new Server(4242);
	server->init(true);
	return 0;
}

