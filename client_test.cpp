#include <iostream>
#include <netdb.h>
#include <zconf.h>
#include "SendablePacket.h"
#include "ReceivablePacket.h"

/*
 * Author: pedrito.
 * Date: 05/08/19
*/

void client_recv(int fd)
{
	unsigned char buffer[512];
	ssize_t n;

	while (true) {
		bzero(buffer, 512);

		n = (recv(fd, buffer, sizeof buffer, 0));
		if (n <= 0) {
			std::cout << "Server error" << std::endl;
			break;
		}
		ReceivablePacket packet(buffer, NULL);
		int opcode = packet.getOpCode();
		std::cout << "Received packet (" << n << ")  with opcode: " << opcode << std::endl;
		switch (opcode) {
			case OP_SAY: {
				std::string msg = packet.readS();
				std::cout << "Server sent you a msg: " << msg << std::endl;
				break;
			}
			case OP_DATE: {
				std::string date = packet.readS();
				std::cout << "Server date: " << date << std::endl;
				break;
			}
			default: {
				break;
			}
		}
	}
}

int client_test(int ac, char **av)
{
	int listenFd, portNo;
	struct sockaddr_in svrAdd;
	struct hostent *server;

	if (ac < 3) {
		std::cerr << "Syntax : ./client <host name> <port>" << std::endl;
		return 0;
	}

	portNo = atoi(av[2]);

	if ((portNo > 65535) || (portNo < 2000)) {
		std::cerr << "Please enter port number between 2000 - 65535" << std::endl;
		return 0;
	}

	//create client skt
	listenFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (listenFd < 0) {
		std::cerr << "Cannot open socket" << std::endl;
		return 0;
	}

	server = gethostbyname(av[1]);

	if (server == NULL) {
		std::cerr << "Host does not exist" << std::endl;
		return 0;
	}

	bzero((char *)&svrAdd, sizeof(svrAdd));
	svrAdd.sin_family = AF_INET;

	bcopy((char *)server->h_addr, (char *)&svrAdd.sin_addr.s_addr, server->h_length);

	svrAdd.sin_port = htons(portNo);

	int checker = connect(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd));

	if (checker < 0) {
		std::cerr << "Cannot connect!" << std::endl;
		return 0;
	}

	unsigned char s[300] = {0};
	long id = 0;
	while (!id) {
		// Wait for an id
		bzero(s, 300);
		ssize_t n = (recv(listenFd, s, sizeof s, 0));
		ReceivablePacket p(s, NULL);
		if (p.getOpCode() == OP_CONNECTION) {
			id = p.readQ();
			std::cout << "Received id " << id << " from server" << std::endl;
		}
	}

	std::thread *clientListener = new std::thread(client_recv, listenFd);
	ssize_t n;
	while (true) {
		bzero(s, 300);
		std::cin.getline((char *)s, 300);
		SendablePacket sendablePacket;
		sendablePacket.writeD(OP_REQUEST_DATE);
		sendablePacket.writeD(20); // USELESS FOR DATE REQUEST
		n = write(listenFd, sendablePacket.getBuffer(), sendablePacket.getSize());
		if (n <= 0) {
			break;
		}
	}
	if (clientListener->joinable()) {
		clientListener->join();
	}
	close(listenFd);
	std::cout << "Bye" << std::endl;
}
