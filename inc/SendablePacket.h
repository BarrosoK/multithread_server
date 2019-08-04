//
// Created by pedrito on 03/08/19.
//

#ifndef SERVER_SENDABLEPACKET_H
#define SERVER_SENDABLEPACKET_H

#include <string>
#define BUFFER_SIZE 512

class SendablePacket {
	private:
	unsigned char buffer[BUFFER_SIZE];
	unsigned int position = 0;
	unsigned int size = 0;
	public:
	SendablePacket();
	virtual ~SendablePacket();
	unsigned char *getBuffer();
	virtual unsigned int getSize();
	void writeD(int data);
	void writeC(char data);
	void writeS(std::string data);
	void writeQ(long data);
};

#endif //SERVER_SENDABLEPACKET_H
