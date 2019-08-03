//
// Created by pedrito on 03/08/19.
//

#include "../../inc/ReceivablePacket.h"

ReceivablePacket::~ReceivablePacket()
{
}

int ReceivablePacket::readD()
{
	int result = buffer[pos++] & 0xff;
	result |= buffer[pos++] << 8 & 0xff00;
	result |= buffer[pos++] << 0x10 & 0xff0000;
	result |= buffer[pos++] << 0x18 & 0xff000000;
	return result;
}

ReceivablePacket::ReceivablePacket(unsigned char *buff, Client *client)
: client(client)
{
	buffer = buff;
	opCode = readD();
}

int ReceivablePacket::readC()
{
	return buffer[pos++] & 0xff;
}

std::string ReceivablePacket::readS()
{
	size_t i;
	char *str;

	for (i = 0; buffer[pos + i] != 0; i++);
	str = (char *)malloc(sizeof(char) * (i + 1));
	memmove(str, &buffer[pos], i + 1);
	pos = pos + (int)i + 1;
	return std::string(str);
}

int ReceivablePacket::getOpCode()
{
	return opCode;
}

unsigned char *ReceivablePacket::getData()
{
	return buffer;
}

Client *ReceivablePacket::getClient()
{
	return client;
}
