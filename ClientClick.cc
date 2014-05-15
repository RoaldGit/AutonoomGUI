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
}

void ClientClick::stuurPing()
{
    NetworkServices::sendMessage(network->ConnectSocket, "ping", 8);
    receiveMessage();
};

void ClientClick::stuurMessage(string message)
{
    char * writable = new char[message.size() + 1];
    std::copy(message.begin(), message.end(), writable);
    writable[message.size()] = '\0';
    NetworkServices::sendMessage(network->ConnectSocket, writable, 8);
    delete[] writable;
};

void ClientClick::receiveMessage()
{
    char dataBuffer[TCP_BUFFER_SIZE];
  // Receive message
			ssize_t received = NetworkServices::receiveMessage(network->ConnectSocket, dataBuffer, TCP_BUFFER_SIZE);
			cout << "sending back a message..."  << endl;
			if(received == 0) cout << "host shut down" << endl;
			if(received == -1) cout << "recv error" << endl;

			// Add end string character for printing, and print received message
			dataBuffer[received] = '\0';
			cout << "Received " << received << " bytes|Message: " << endl << "------" << endl << dataBuffer << "------" << endl;
};
