//
// Created by pedrito on 03/08/19.
//

#include <strings.h>
#include <cstring>
#include <SendablePacket.h>
#include <iostream>

SendablePacket::~SendablePacket()
{
}

SendablePacket::SendablePacket()
{
	bzero(buffer, BUFFER_SIZE);
}

/*
 * Int
 */
void SendablePacket::writeD(int data)
{
	buffer[position++] |= data & 0xff;
	buffer[position++] |= data >> 8 & 0xff;
	buffer[position++] |= data >> 16 & 0xff;
	buffer[position++] |= data >> 24 & 0xff;
	size += 4;
}

unsigned char *SendablePacket::getBuffer()
{
	return buffer;
}


void SendablePacket::writeC(char data)
{
	buffer[position++] |= data & 0xff;
	size += 1;
}

void SendablePacket::writeS(std::string data)
{
	memmove(&buffer[position], data.c_str(), data.size());
	buffer[position + data.size()] = 0;
	position = position + (int)data.size() + 1;
	size += data.size();
}

unsigned int SendablePacket::getSize()
{
	return size;
}

/*
 * Long
 */
void SendablePacket::writeQ(long data)
{
	buffer[position++] |= (int)(data & 0xff);
	buffer[position++] |= (int)(data >> 8 & 0xff);
	buffer[position++] |= (int)(data >> 16 & 0xff);
	buffer[position++] |= (int)(data >> 24 & 0xff);
	buffer[position++] |= (int)(data >> 32 & 0xff);
	buffer[position++] |= (int)(data >> 40 & 0xff);
	buffer[position++] |= (int)(data >> 48 & 0xff);
	buffer[position++] |= (int)(data >> 56 & 0xff);
	size += 8;
}

/*
 * Short
 */
void SendablePacket::writeH(short data)
{
	buffer[position++] |= data & 0xff;
	buffer[position++] |= data >> 8 & 0xff;
	size += 2;
}
