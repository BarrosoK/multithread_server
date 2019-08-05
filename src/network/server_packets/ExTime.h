//
// Created by pedrito on 03/08/19.
//

#include <Time.h>
#include "SendablePacket.h"

class ExTime : public SendablePacket {
	public:

		/*
		 * Send server's time
		 */
		explicit ExTime() : SendablePacket()
		{
			writeD(OP_TIME);
			writeS(Time::getTime());
		}
};


