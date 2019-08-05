//
// Created by pedrito on 03/08/19.
//

#include <Time.h>
#include "SendablePacket.h"

class ExKick : public SendablePacket {
	public:
		explicit ExKick(const std::string &reason) : SendablePacket()
		{
			writeD(OP_KICK);
			writeS(reason);
		}
};


