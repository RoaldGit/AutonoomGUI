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

class ClientClick
{

public:

	ClientClick();
	~ClientClick(void);

	ClientNetwork* network;
};

#endif /* CLIENTCLICK_H_ */
