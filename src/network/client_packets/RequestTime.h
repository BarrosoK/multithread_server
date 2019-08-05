//
// Created by pedrito on 03/08/19.
//

#include <server_packets/ExTime.h>
#include "ReceivablePacket.h"

class RequestTime : ReceivablePacket {
	public:

		explicit RequestTime(ReceivablePacket *packet) : ReceivablePacket(packet)
		{
			getClient()->sendPacket(new ExTime());
		}
};


