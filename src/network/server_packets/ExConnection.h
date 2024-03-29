//
// Created by pedrito on 03/08/19.
//

#include "SendablePacket.h"

class ExConnection : public SendablePacket {
	public:

		/*
		 * Sent on connection
		 */
		explicit ExConnection(long id) : SendablePacket()
		{
			writeD(OP_CONNECTION); // OPCODE
			writeQ(id); // id
		}
};


