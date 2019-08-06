//
// Created by pedrito on 03/08/19.
//

#include <iostream>
#include <server_packets/ExClient.h>
#include "Client.h"
#include "Server.h"
#include "ReceivablePacket.h"

void handleClient(Client *client)
{
	client->setConnected(true);
	unsigned char buffer[BUFFER_SIZE];
	ssize_t n;
	//TODO: Check if the gui had enough time to init
	ServerUI::getInstance()->addClient(client);

	while (client->isConnected()) {
		memset(buffer, 0, sizeof buffer);
		n = (recv(client->getSocket(), buffer, sizeof buffer, 0));
		if (n == 0) {
			// Disconnected
			Server::removeClient(client);
			break;
		} else if (n < 0) {
			// Error
			Server::removeClient(client);
			break;
		} else {
			ReceivablePacket packet(buffer, client);
			handlePacket(&packet);
		}
	}
}