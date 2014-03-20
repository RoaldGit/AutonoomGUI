/*
 * ClientClick.cc
 *
 *  Created on: 19 mrt. 2014
 *      Author: Stef
 */

#include "ClientClick.h"

ClientClick::ClientClick(void)
{
	network = new ClientNetwork();

//	const unsigned int packet_size = sizeof(Packet);
//	char packet_data[packet_size];
//
//	Packet packet;
//	packet.packet_type = INIT_CONNECTION;
//
//	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, "ping", 8);
}
