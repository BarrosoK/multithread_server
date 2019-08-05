//
// Created by pedrito on 03/08/19.
//

#include <Time.h>
#include <Server.h>
#include "SendablePacket.h"

class ExOther : public SendablePacket {
	public:
		explicit ExOther(long id) : SendablePacket()
		{
			writeD(OP_OTHER);
			writeQ(Server::clients.empty() ? 0 : Server::clients.size() - 1);
			for (auto const &c: Server::clients) {
				if (c.first->getId() != id) {
					writeQ(c.first->getId());
				}
			}
		}
};


