//
// Created by pedrito on 03/08/19.
//

#include <server_packets/ExOther.h>
#include "ReceivablePacket.h"

class RequestOther : ReceivablePacket {
	public:

		explicit RequestOther(ReceivablePacket *packet) : ReceivablePacket(packet)
		{
			getClient()->sendPacket(new ExOther(getClient()->getId()));
		}
};


