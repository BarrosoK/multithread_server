//
// Created by pedrito on 03/08/19.
//

#ifndef SERVER_RECEIVABLEPACKET_H
#define SERVER_RECEIVABLEPACKET_H

#include <iostream>
#include <cstring>
#include "Client.h"

class ReceivablePacket {
	private:
		unsigned char *buffer;
		unsigned int pos = 0;
		int opCode;
		Client *client;
	public:
		ReceivablePacket(unsigned char *buff, Client *client);
		virtual ~ReceivablePacket();
		int readD();
		int readC();
		std::string readS();
		int getOpCode();
		unsigned char *getData();
		Client *getClient();
};

#endif //SERVER_RECEIVABLEPACKET_H
