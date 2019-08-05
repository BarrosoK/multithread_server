//
// Created by pedrito on 03/08/19.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <mutex>
#include <vector>
#include <thread>
#include <regex>
#include "Client.h"
#include "LoggerFile.h"

enum SERVER_ERROR_CODE : int {
	INVALID_PORT = 23,
	LISTEN_ERROR = 24
};

class Server {
	private:
		int port;
		std::string addr;
		bool running;
		int serverSocket;
		struct sockaddr_in serverAddr, clientAddr;
		unsigned int maxConnections;
		static std::mutex lock;
		void loadEvents();

	public:
		Server(int port, unsigned int maxConnections = 50);
		int init(bool start = false);
		int start();

	public:
		static void lockMutex();
		static void unlockMutex();
		static std::vector<std::pair<Client *, std::thread *>> clients;
		static LoggerFile logger;
		static void broadcast(SendablePacket *packet);
		static Client *findClientByThreadId(std::thread::id id);
		static Client *findClientById(long id);
		static bool removeClientByThreadId(std::thread::id id);
		static bool removeClient(Client *client);
};

#endif //SERVER_SERVER_H
