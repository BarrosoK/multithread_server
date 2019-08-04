//
// Created by pedrito on 03/08/19.
//

#include "SendablePacket.h"

class ExMove: public SendablePacket {
	public:

	explicit ExMove(long id, int x, int y) : SendablePacket()
		{
			writeD(15); // OPCODE
			writeQ(id);
			writeD(x);
			writeD(y);
		}
};


