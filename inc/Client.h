//
// Created by pedrito on 03/08/19.
//

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include "ReceivablePacket.h"
#include "SendablePacket.h"

class Client {
	private:
	int id;
	int socket;

	public:
	Client();
	int getId();
	int getSocket();
	void setId(int id);
	void setSocket(int socket);
	void sendPacket(SendablePacket *packet);
};

void handlePacket(ReceivablePacket *packet);
void handleClient(Client *client);

#endif //SERVER_CLIENT_H
