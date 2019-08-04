//
// Created by pedrito on 03/08/19.
//

#include "../../inc/ReceivablePacket.h"
#include "../network/RequestLogin.h"
#include "../../inc/SendablePacket.h"

void handlePacket(ReceivablePacket *packet) {
	int opCode = packet->getOpCode();
	std::cout << "Packet received with opcode: " << opCode << std::endl;
	switch (opCode) {
	case 12:
		new RequestLogin(packet);
		break;
	default:break;
	}
}