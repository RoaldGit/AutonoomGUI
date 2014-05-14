/*
 * ClientNetwork.h
 *
 *  Created on: 13 mrt. 2014
 *      Author: Stef
 */

#ifndef CLIENTNETWORK_H_
#define CLIENTNETWORK_H_

#include <ws2tcpip.h>
#include <winsock2.h>
#include "NetworkServices.h"
#include "NetworkData.h"
#include <stdio.h>

// size of buffer
#define DEFAULT_BUFLEN 512
// port to connect sockets through
#define DEFAULT_PORT "5555"
// Linken van libraries
/*
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")*/

class ClientNetwork
{

public:
	// voor error check
	int iResult;
	//client socket
	SOCKET ConnectSocket;


	ClientNetwork(void);
	~ClientNetwork(void);
};
#endif /* CLIENTNETWORK_H_ */

