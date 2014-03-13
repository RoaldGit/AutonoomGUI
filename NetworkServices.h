/*
 * NetworkServices.h
 *
 *  Created on: 13 mrt. 2014
 *      Author: Stef
 */

#ifndef NETWORKSERVICES_H_
#define NETWORKSERVICES_H_

#pragma once
#include <winsock2.h>
#include <Windows.h>

class NetworkServices
{
public:

	static int sendMessage(SOCKET curSocket, char * message, int messageSize);
	static int receiveMessage(SOCKET curSocket, char* buffer, int bufSize);
};


#endif /* NETWORKSERVICES_H_ */
