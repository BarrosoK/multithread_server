//
// Created by pedrito on 03/08/19.
//

#include "ReceivablePacket.h"
#include "client_packets/RequestLogin.h"
#include "SendablePacket.h"

void handlePacket(ReceivablePacket *packet)
{
	int opCode = packet->getOpCode();
	switch (opCode) {
		case 12: {
			new RequestLogin(packet);
			break;
		}
		default: {
			std::cerr << "Unknown packet received with opcode: " << opCode << std::endl;
			break;
		}
	}
}