//
// Created by pedrito on 03/08/19.
//

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include <thread>
#include "SendablePacket.h"

class ReceivablePacket;

class Client {
	private:
	int id;
	int socket;
		std::thread::id threadId;

	public:
	Client();
	int getId();
	int getSocket();
	void setId(int id);
	void setSocket(int socket);
	void sendPacket(SendablePacket *packet);
		void setThreadId(std::thread::id);
		std::thread::id getThreadId();
};

void handlePacket(ReceivablePacket *packet);
void handleClient(Client *client);

#endif //SERVER_CLIENT_H
