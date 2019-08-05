//
// Created by pedrito on 03/08/19.
//

#include <server_packets/ExDate.h>
#include "ReceivablePacket.h"

class RequestDate : ReceivablePacket {
	public:

		explicit RequestDate(ReceivablePacket *packet) : ReceivablePacket(packet)
		{
			getClient()->sendPacket(new ExDate());
		}
};


