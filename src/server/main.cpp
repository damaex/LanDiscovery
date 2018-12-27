#include <winsock2.h>
#include <string>
#include <iostream>

#define MAXRECVSTRING 255  /* Longest string to receive */

void log(const std::string& message) {
	std::cout << message << std::endl;
}

void DieWithError(const std::string& errorMessage) {
	log(errorMessage);
	exit(1);
}

void socketClose(SOCKET socket) {
	closesocket(socket);
}

int main(int argc, char *argv[])
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0) {
		DieWithError("WSAStartup failed with error: " +  std::to_string(iResult));
	}

	SOCKET sock;                         /* Socket */
	struct sockaddr_in broadcastAddr; /* Broadcast Address */
	unsigned short broadcastPort;     /* Port */
	char recvString[MAXRECVSTRING + 1]; /* Buffer for received string */
	int recvStringLen;                /* Length of received string */

	if (argc != 2)    /* Test for correct number of arguments */
	{
		log("Usage: server <Broadcast Port>");
		exit(1);
	}

	broadcastPort = atoi(argv[1]);   /* First arg: broadcast port */

	/* Create a best-effort datagram socket using UDP */
	if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		DieWithError("socket() failed");

	/* Construct bind structure */
	memset(&broadcastAddr, 0, sizeof(broadcastAddr));   /* Zero out structure */
	broadcastAddr.sin_family = AF_INET;                 /* Internet address family */
	broadcastAddr.sin_addr.s_addr = htonl(INADDR_ANY);  /* Any incoming interface */
	broadcastAddr.sin_port = htons(broadcastPort);      /* Broadcast port */

	/* Bind to the broadcast port */
	if (bind(sock, (struct sockaddr *) &broadcastAddr, sizeof(broadcastAddr)) < 0)
		DieWithError("bind() failed");

	for (;;) /* Run forever */
	{
		/* Receive a single datagram from the server */
		if ((recvStringLen = recvfrom(sock, recvString, MAXRECVSTRING, 0, NULL, 0)) < 0)
			DieWithError("recvfrom() failed");

		recvString[recvStringLen] = '\0';
		log("Received: " + std::string(recvString));    /* Print the received string */
	}

	socketClose(sock);
	return 0;
}