//
// Created by pedrito on 03/08/19.
//

#include "SendablePacket.h"

class ExLogin: public SendablePacket {
	public:

	explicit ExLogin(int status) : SendablePacket()
		{
			writeD(124525); // OPCODE
			writeD(status);
			writeS("string test");
		}
};


