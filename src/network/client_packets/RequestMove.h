//
// Created by pedrito on 03/08/19.
//

#include <Server.h>
#include <server_packets/ExMove.h>
#include "ReceivablePacket.h"

class RequestMove: ReceivablePacket {
	public:

	explicit RequestMove(ReceivablePacket *packet) : ReceivablePacket(packet)
		{
			long id = getClient()->getId();
			int x = readD();
			int y = readD();
			Server::broadcast(new ExMove(id, x, y));
		}
};


