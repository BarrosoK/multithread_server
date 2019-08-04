//
// Created by pedrito on 03/08/19.
//

#include "../../inc/ReceivablePacket.h"
#include "../../inc/SendablePacket.h"
#include "ExLogin.h"

class RequestLogin: ReceivablePacket {
	public:

	explicit RequestLogin(ReceivablePacket *packet) : ReceivablePacket(packet->getData(), packet->getClient())
		{
			std::string login = readS();
			// 12 -> LOGIN OK (example)
			getClient()->sendPacket(new ExLogin(12));
		}
};


