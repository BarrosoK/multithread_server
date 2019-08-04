//
// Created by pedrito on 03/08/19.
//

#include <sys/socket.h>
#include <cstring>
#include <iostream>
#include <server_packets/ExConnection.h>
#include "Client.h"

long Client::getId()
{
	return this->id;
}

int Client::getSocket()
{
	return this->socket;
}

Client::Client(int socket) : socket(socket)
{
	id = (long)this;
	std::cout << "new client " << id << std::endl;
	// send to the client his id
	sendPacket(new ExConnection(id));
}

void Client::setSocket(int socket)
{
	this->socket = socket;
}

void Client::sendPacket(SendablePacket *packet)
{
	ssize_t n = send(getSocket(), packet->getBuffer(), packet->getSize(), 0);
	std::cout << n << " bytes sent." << std::endl;
}

void Client::setThreadId(std::thread::id id)
{
	threadId = id;
}

std::thread::id Client::getThreadId()
{
	return threadId;
}

