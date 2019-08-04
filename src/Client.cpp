//
// Created by pedrito on 03/08/19.
//

#include <sys/socket.h>
#include <cstring>
#include <iostream>
#include "../inc/Client.h"

int Client::getId()
{
	return this->id;
}

int Client::getSocket()
{
	return this->socket;
}

Client::Client()
{
}

void Client::setId(int id)
{
	this->id = id;
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

