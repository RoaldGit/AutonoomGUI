/*
 * ClientClick.h
 *
 *  Created on: 19 mrt. 2014
 *      Author: Stef
 */

#ifndef CLIENTCLICK_H_
#define CLIENTCLICK_H_

#include <winsock2.h>
#include <Windows.h>
#include "ClientNetwork.h"
#include "NetworkData.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#define TCP_BUFFER_SIZE 1024

class ClientClick
{

public:

	ClientClick();
	~ClientClick(void);
	void stuurPing();
	void stuurMessage(string message);
	void receiveMessage();

	ClientNetwork* network;
};

#endif /* CLIENTCLICK_H_ */
