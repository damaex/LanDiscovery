#include "LanDiscovery.h"

bool LanDiscovery::setupSocket()
{
#ifdef _WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0) {
		Console::writeLine("WSAStartup failed with error: " + std::to_string(iResult));
		return false;
	}
#endif

	return true;
}

void LanDiscovery::socketClose(SOCKET socket) {
#ifdef _WIN32
	closesocket(socket);
#else
	close(socket);
#endif
}

void LanDiscovery::runServer()
{
}

std::vector<std::string> LanDiscovery::getBroadcast()
{
	LanDiscovery::setupSocket();
	return std::vector<std::string>();
}

void LanDiscovery::serverStart()
{
	if (!this->serverRunning) {
		this->serverRunning = true;
		this->serverThread = std::thread(&LanDiscovery::runServer, this);
	}
}

void LanDiscovery::serverStop()
{
}

bool LanDiscovery::isServerRunning()
{
	return false;
}

std::vector<std::string> LanDiscovery::getServerList(unsigned short port)
{
	std::vector<std::string> broadcastIP = this->getBroadcast();

	return std::vector<std::string>();
}
