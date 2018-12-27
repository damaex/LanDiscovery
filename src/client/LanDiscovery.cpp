#include "LanDiscovery.h"

#include <winsock2.h>

bool LanDiscovery::setupSocket()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return false;
	}

	return true;
}

std::vector<std::string> LanDiscovery::getBroadcast()
{
	this->setupSocket();
	return std::vector<std::string>();
}

std::vector<std::string> LanDiscovery::getServerList(unsigned short port)
{
	std::vector<std::string> broadcastIP = this->getBroadcast();

	return std::vector<std::string>();
}
