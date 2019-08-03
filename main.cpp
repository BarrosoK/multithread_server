#include <iostream>
#include "inc/Server.h"
#include "inc/SendablePacket.h"
#include "inc/ReceivablePacket.h"

int main()
{
	/* RECEIVE TEST
	SendablePacket sendablePacket;
	sendablePacket.writeD(12);
	sendablePacket.writeS("login");

	ReceivablePacket receivablePacket(sendablePacket.getBuffer());
	handlePacket(&receivablePacket);
	*/

	Server *server = new Server(4242);
	server->init(true);
	return 0;
}