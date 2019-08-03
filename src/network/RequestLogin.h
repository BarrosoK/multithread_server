//
// Created by pedrito on 03/08/19.
//

#include "../../inc/ReceivablePacket.h"

class RequestLogin: ReceivablePacket {
	public:
	explicit RequestLogin(ReceivablePacket *packet) : ReceivablePacket(packet->getData(), packet->getClient())
		{
			std::string login = readS();
			std::cout << "login received " << login << std::endl;
			// getClient()->sendPacket()
		}
};


