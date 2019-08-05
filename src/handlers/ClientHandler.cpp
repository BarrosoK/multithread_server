//
// Created by pedrito on 03/08/19.
//

#include <iostream>
#include "Client.h"
#include "Server.h"
#include "ReceivablePacket.h"

void handleClient(Client *client)
{
	client->setConnected(true);
	unsigned char buffer[BUFFER_SIZE];
	int n;

	while (client->isConnected()) {
		memset(buffer, 0, sizeof buffer);
		n = static_cast<int>(recv(client->getSocket(), buffer, sizeof buffer, 0));
		if (n == 0) {
			Server::removeClient(client);
			break;
		} else if (n < 0) {
			std::cerr << "Error while receiving message from client" << std::endl;
			Server::removeClient(client);
			break;
		} else {
			ReceivablePacket packet(buffer, client);
			handlePacket(&packet);
		}
	}
}