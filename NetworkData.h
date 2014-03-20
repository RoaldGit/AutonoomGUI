/*
 * NetworkData.h
 *
 *  Created on: 19 mrt. 2014
 *      Author: Stef
 */

#ifndef NETWORKDATA_H_
#define NETWORKDATA_H_

#include <string.h>

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {
	INIT_CONNECTION = 0,

	ACTION_EVENT = 1,
};

struct Packet {
	unsigned int packet_type;

	void serialize(char *data){
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char *data) {
		memcpy(this, data, sizeof(Packet));
	}
};


#endif /* NETWORKDATA_H_ */
