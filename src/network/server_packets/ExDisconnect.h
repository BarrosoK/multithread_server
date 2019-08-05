//
// Created by pedrito on 03/08/19.
//

#include <Client.h>
#include "SendablePacket.h"

class ExDisconnect : public SendablePacket {
	public:

		/*
		 * Sent on connection
		 */
		explicit ExDisconnect(Client *client) : SendablePacket()
		{
			writeD(OP_DISCONNECT); // OPCODE
			writeQ(client->getId()); // id
		}
};


