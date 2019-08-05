//
// Created by pedrito on 03/08/19.
//

#include <ReceivablePacket.h>


ReceivablePacket::~ReceivablePacket()
{
}

int ReceivablePacket::readD()
{
	int result = buffer[pos++] & 0xff;
	result |= (buffer[pos++] & 0xffL) << 8;
	result |= (buffer[pos++] & 0xffL) << 16;
	result |= (buffer[pos++] & 0xffL) << 24;
	return result;
}

ReceivablePacket::ReceivablePacket(unsigned char *buff, Client *client) : client(client)
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

ReceivablePacket::ReceivablePacket(ReceivablePacket *packet) : buffer(packet->getData()),
	client(packet->getClient())
{
	opCode = readD();
}

long ReceivablePacket::readQ()
{
	long result = buffer[pos++] & 0xff;
	result |= (buffer[pos++] & 0xffL) << 8;
	result |= (buffer[pos++] & 0xffL) << 16;
	result |= (buffer[pos++] & 0xffL) << 24;
	result |= (buffer[pos++] & 0xffL) << 32;
	result |= (buffer[pos++] & 0xffL) << 40;
	result |= (buffer[pos++] & 0xffL) << 48;
	result |= (buffer[pos++] & 0xffL) << 56;
	return result;
}

short ReceivablePacket::readH()
{
	int result = (buffer[pos++] & 0xFFFF);
	result |= (buffer[pos++] & 0xff) << 8;
	return (short) result;
}
