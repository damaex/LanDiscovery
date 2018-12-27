#ifndef LANDISCOVERY_H
#define LANDISCOVERY_H

#include <string>
#include <vector>

class LanDiscovery {
private:
	bool setupSocket();
	std::vector<std::string> getBroadcast();



public:
	std::vector<std::string> getServerList(unsigned short port);
};

#endif //LANDISCOVERY_H