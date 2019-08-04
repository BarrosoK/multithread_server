#include <iostream>
#include <netdb.h>
#include "Server.h"
#include "SendablePacket.h"
#include "ReceivablePacket.h"


int client_test (int argc, char* argv[])
{
	int listenFd, portNo;
	struct sockaddr_in svrAdd;
	struct hostent *server;

	if(argc < 3)
	{
		std::cerr<<"Syntax : ./client <host name> <port>"<<std::endl;
		return 0;
	}

	portNo = atoi(argv[2]);

	if((portNo > 65535) || (portNo < 2000))
	{
		std::cerr<<"Please enter port number between 2000 - 65535"<<std::endl;
		return 0;
	}

	//create client skt
	listenFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(listenFd < 0)
	{
		std::cerr << "Cannot open socket" << std::endl;
		return 0;
	}

	server = gethostbyname(argv[1]);

	if(server == NULL)
	{
		std::cerr << "Host does not exist" << std::endl;
		return 0;
	}

	bzero((char *) &svrAdd, sizeof(svrAdd));
	svrAdd.sin_family = AF_INET;

	bcopy((char *) server->h_addr, (char *) &svrAdd.sin_addr.s_addr, server -> h_length);

	svrAdd.sin_port = htons(portNo);

	int checker = connect(listenFd,(struct sockaddr *) &svrAdd, sizeof(svrAdd));

	if (checker < 0)
	{
		std::cerr << "Cannot connect!" << std::endl;
		return 0;
	}
	unsigned char buffer[512];
	int n;


	n = static_cast<int>(recv(listenFd, buffer, sizeof buffer, 0));
	ReceivablePacket pa(buffer, NULL);
	long id  = pa.readQ();
	std::cout << "id: " << id << std::endl;
	//send stuff to server
	for(;;)
	{
		char s[300];
		//cin.clear();
		//cin.ignore(256, '\n');
		std::cout << "Enter stuff: ";
		bzero(s, 301);
		std::cin.getline(s, 300);

		SendablePacket sendablePacket;
		sendablePacket.writeD(12);
		sendablePacket.writeS("login");
		sendablePacket.writeS("password");
		write(listenFd, sendablePacket.getBuffer(), strlen((char *)sendablePacket.getBuffer()));
		n = static_cast<int>(recv(listenFd, buffer, sizeof buffer, 0));
		std::cout << "Received: " << buffer << std::endl;
	}
}


int main(int ac, char **av)
{
	if (ac > 1) {
		client_test(ac, av);
		return 0;
	}
	Server *server = new Server(4242);
	server->init(true);
	return 0;
}

