//
// Created by pedrito on 03/08/19.
//

#include <iostream>
#include "../../inc/Client.h"
#include "../../inc/Server.h"
#include "../../inc/ReceivablePacket.h"

void handleClient(Client *client) {
	bool listening = true;
	unsigned char buffer[BUFFER_SIZE];
	int n;

	// SET HIM UUID
	std::cout << "new client" << std::endl;
	while (listening) {
		memset(buffer, 0, sizeof buffer);
		n = static_cast<int>(recv(client->getSocket(), buffer, sizeof buffer, 0));
		if(n == 0) {
			std::cout << "Client diconnected" << std::endl;
			close(client->getSocket());
			Server::lockMutex();
			// TODO: REMOVE CLIENT
			/*
			index = Server::FindClientIndex(c);
			cout << "Erasing user in position " << index << " whose name id is: "
				<< Server::clients[index].id << endl;
			Server::clients.erase(Server::clients.begin() + index);
			*/
			Server::unlockMutex();
			break;
		}
		else if(n < 0) {
			std::cerr << "Error while receiving message from client: " << std::endl;
		}
		else {
			ReceivablePacket packet(buffer, client);
			handlePacket(&packet);
		}
	}
}