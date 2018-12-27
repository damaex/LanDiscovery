#ifndef LANDISCOVERY_H
#define LANDISCOVERY_H

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define	SOCKET		int
#endif

#include <string>
#include <vector>
#include <thread>

#include "Console.h"

class LanDiscovery {
private:
	std::thread serverThread;

	bool serverRunning = false;

	void runServer();

	std::vector<std::string> getBroadcast();

public:
	static bool setupSocket();

	static void socketClose(SOCKET socket);

	void serverStart();

	void serverStop();

	bool isServerRunning();

	std::vector<std::string> getServerList(unsigned short port);
};

#endif //LANDISCOVERY_H