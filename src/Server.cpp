#include <utility>
#include <iostream>
#include <Server.h>

//
// Created by pedrito on 03/08/19.
//

std::mutex Server::lock;

std::vector<std::pair<Client *, std::thread *>> Server::clients;

Server::Server(int port, unsigned int maxConnections) : port(port), addr(std::move(addr)),
	maxConnections(maxConnections)
{
	Server::clients.reserve(maxConnections);
}

int Server::init(bool start)
{
	if (port < 0 || port > 65535) {
		std::cout << "Invalid port" << std::endl;
		return INVALID_PORT;
	}
	// Create the socket
	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	// Configure settings of the server address struct
	// Address family = Internet
	serverAddr.sin_family = AF_INET;
	//Set port number, using htons function to use proper byte order
	serverAddr.sin_port = htons(port);
	//Set IP address to localhost
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	//Set all bits of the padding field to 0
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	if (start) {
		this->start();
	}
	return 0;
}

int Server::start()
{
	try {
		int yes = 1;
		//Avoid bind error if the socket was not close()'d last time;
		setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
		//Bind the address struct to the socket
		bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
		//Listen on the socket, with max connection requests queued
		if (listen(serverSocket, maxConnections) == 0)
			std::cout << "Listening on port " << port << std::endl;
		else
			throw LISTEN_ERROR;
		running = true;
		socklen_t cliSize = sizeof(sockaddr_in);
		while (running) {
			int fd = accept(serverSocket, (struct sockaddr *)&clientAddr, &cliSize);
			Client *c = new Client(fd);
			if (fd < 0) {
				std::cerr << "Error on accept" << std::endl;
				continue;
			}
			Server::lockMutex();
			std::thread *handler = new std::thread(handleClient, c);
			c->setThreadId(handler->get_id());
			Server::clients.emplace_back(std::make_pair(c, handler));
			Server::unlockMutex();
		}
		for (auto &t: Server::clients) {
			if (t.second->joinable())
				t.second->join();
		}
	} catch (SERVER_ERROR_CODE e) {
		std::cout << "Error(" << e << "): ";
		switch (e) {
			case LISTEN_ERROR:
				std::cout << "Listening" << std::endl;
				break;
			default:
				std::cout << "Unknown error code " << e << std::endl;
				break;
		}
	}
	return 0;
}

void Server::lockMutex()
{
	Server::lock.lock();
}

void Server::unlockMutex()
{
	Server::lock.unlock();
}

void Server::broadcast(SendablePacket *packet)
{
	for (const std::pair<Client *, std::thread *> &c : Server::clients) {
		Client *client = c.first;
		client->sendPacket(packet);
	}
}

Client *Server::findClientByThreadId(std::thread::id id)
{
	for (const std::pair<Client *, std::thread *> &c : Server::clients) {
		if (c.second->get_id() == id)
			return c.first;
	}
}

bool Server::removeClientByThreadId(std::thread::id id)
{
	Server::lockMutex();
	int index = 0;
	for (const std::pair<Client *, std::thread *> &c : Server::clients) {
		if (c.second->get_id() == id) {
			close(c.first->getSocket());
			Server::clients.erase(Server::clients.begin() + index);
		}
		index++;
	}
	Server::unlockMutex();
}

bool Server::removeClient(Client *client)
{
	return Server::removeClientByThreadId(client->getThreadId());
}

Client *Server::findClientById(long id)
{
	for (const std::pair<Client *, std::thread *> &c : Server::clients) {
		if (c.first->getId() == id)
			return c.first;
	}
}




