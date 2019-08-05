//
// Created by pedrito on 03/08/19.
//

#include "ReceivablePacket.h"
#include <client_packets/RequestMove.h>
#include <client_packets/RequestDate.h>
#include <client_packets/RequestTime.h>

void handlePacket(ReceivablePacket *packet)
{
	int opCode = packet->getOpCode();
	switch (opCode) {
		case OP_REQUEST_DATE: {
			new RequestDate(packet);
			break;
		}
		case OP_REQUEST_TIME: {
			new RequestTime(packet);
			break;
		}
		default: {
			std::cerr << "Unknown packet received with opcode: " << opCode << std::endl;
			break;
		}
	}
}