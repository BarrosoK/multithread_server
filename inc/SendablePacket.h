//
// Created by pedrito on 03/08/19.
//

#ifndef SERVER_SENDABLEPACKET_H
#define SERVER_SENDABLEPACKET_H

#include <string>

#define BUFFER_SIZE 512

enum SENDABLE_OPCODE: int {
	OP_KICK = 4,
	OP_OTHER = 5,
	OP_NEW_CLIENT = 6,
	OP_DISCONNECT = 7,
	OP_CONNECTION = 15, // send to the new client his id
	OP_SAY = 23,
	OP_DATE = 25,
	OP_TIME = 26,
};

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
		void writeH(short data);
};

#endif //SERVER_SENDABLEPACKET_H
