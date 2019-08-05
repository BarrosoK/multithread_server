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
	protected:
		ReceivablePacket(ReceivablePacket *pPacket);
	public:
		ReceivablePacket(unsigned char *buff, Client *client);
		virtual ~ReceivablePacket();
		int getOpCode();
		Client *getClient();
		unsigned char *getData();
		int readD();
		int readC();
		std::string readS();
		long readQ();
		short readH();
};

#endif //SERVER_RECEIVABLEPACKET_H
