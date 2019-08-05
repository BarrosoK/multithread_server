//
// Created by pedrito on 03/08/19.
//

#include <Time.h>
#include "SendablePacket.h"

class ExDate : public SendablePacket {
	public:

		/*
		 * Sent on connection
		 */
		explicit ExDate() : SendablePacket()
		{
			writeD(OP_DATE);
			writeS(Time::getDate());
		}
};


