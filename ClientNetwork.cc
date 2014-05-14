/*
 * ClientNetwork.cc
 *
 *  Created on: 13 mrt. 2014
 *      Author: Stef
 */

#define _WIN32_WINNT 0x501
//#include <ws2tcpip.h>
#include "ClientNetwork.h"

ClientNetwork::ClientNetwork(void) {

	//create WSADATA object
	WSADATA wsaData;

	//socket
	ConnectSocket = INVALID_SOCKET;

	// addressinfo
	struct addrinfo *result = NULL,
					*ptr = NULL,
					hints;

	//Init Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(1);
	}

	//set address info
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP; // TCP connection!!!

	iResult = getaddrinfo("192.168.7.2", DEFAULT_PORT, &hints, &result);

	if(iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		exit(1);
	}

	// Poging tot connecten tot een address
	for(ptr = result; ptr != NULL; ptr=ptr->ai_next) {
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

		if(ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %d\n", WSAGetLastError());
			WSACleanup();
			exit(1);
		}

		// Connect to server
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if(iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			printf("The server is down... did not connect");

		}
	}

	// no longed need address info for server
	freeaddrinfo(result);

	//if connection failed
	if(ConnectSocket == INVALID_SOCKET)
	{
		printf("Unable to connect to server!\n");
		WSACleanup();
		exit(1);
	}

	// Set the mode of the socket to be nonblocking
	u_long iMode = 1;
	iResult = ioctlsocket(ConnectSocket, FIONBIO, &iMode);
	if (iResult == SOCKET_ERROR)
	{
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		exit(1);
	}

	//disable nagle
	char value = 1;
	setsockopt(ConnectSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
}
