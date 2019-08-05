//
// Created by pedrito on 03/08/19.
//

#include <Time.h>
#include "SendablePacket.h"

class ExDate : public SendablePacket {
	public:

		/*
		 * Send server's date
		 */
		explicit ExDate() : SendablePacket()
		{
			writeD(OP_DATE);
			writeS(Time::getDate());
		}
};


