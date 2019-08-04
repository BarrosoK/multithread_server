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
		long id;
		int socket;
		std::thread::id threadId;

	public:
		explicit Client(int socket = 0);
		long getId();
		int getSocket();
		void setSocket(int socket);
		void sendPacket(SendablePacket *packet);
		void setThreadId(std::thread::id);
		std::thread::id getThreadId();
};

void handlePacket(ReceivablePacket *packet);
void handleClient(Client *client);

#endif //SERVER_CLIENT_H
