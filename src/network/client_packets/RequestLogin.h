//
// Created by pedrito on 03/08/19.
//

#include "ReceivablePacket.h"
#include "server_packets/ExLogin.h"

class RequestLogin : ReceivablePacket {
	public:

		explicit RequestLogin(ReceivablePacket *packet) : ReceivablePacket(packet)
		{
			std::string login = readS();
			std::string password = readS();
			// 12 -> LOGIN OK (example)
			// Server::broadcast(new ExLogin(1));
			getClient()->sendPacket(new ExLogin(12));
		}
};


