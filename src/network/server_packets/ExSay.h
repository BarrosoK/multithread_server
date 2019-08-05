//
// Created by pedrito on 03/08/19.
//

#include "SendablePacket.h"

class ExSay : public SendablePacket {
	public:

		/*
		 * Sent on connection
		 */
		explicit ExSay(const std::string &msg) : SendablePacket()
		{
			writeD(OP_SAY);
			writeS(msg);
		}
};


