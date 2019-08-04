//
// Created by pedrito on 03/08/19.
//

#include <strings.h>
#include <cstring>
#include "../../inc/SendablePacket.h"

SendablePacket::~SendablePacket()
{
}

SendablePacket::SendablePacket()
{
	bzero(buffer, BUFFER_SIZE);
}

void SendablePacket::writeD(int data)
{
	buffer[position++] |= data & 0xff;
	buffer[position++] |= data >> 8 & 0xff;
	buffer[position++] |= data >> 16 & 0xff;
	buffer[position++] |= data >> 24 & 0xff;
}

unsigned char *SendablePacket::getBuffer()
{
	return buffer;
}

void SendablePacket::writeC(char data)
{
	buffer[position++] |= data & 0xff;
}

void SendablePacket::writeS(std::string data)
{
	memmove(&buffer[position], data.c_str(), data.size());
	buffer[position + data.size()] = 0;
	position = position + (int)data.size() + 1;
}

unsigned int SendablePacket::getSize()
{
	return 512;
}
