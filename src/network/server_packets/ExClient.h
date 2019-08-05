//
// Created by pedrito on 03/08/19.
//

#include <Client.h>
#include "SendablePacket.h"

class ExClient : public SendablePacket {
	public:

		/*
		 * Sent on connection
		 */
		explicit ExClient(Client *client) : SendablePacket()
		{
			writeD(OP_NEW_CLIENT); // OPCODE
			writeQ(client->getId()); // id
		}
};


