/*
 * main.cpp
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#include <string>
#include <iostream>

#include "Server.h"



int main(int argc, char**argv){
	if(argc != 7){
		std::cout<<"missed parameter "<< argc<<std::endl;

		return 0;
	}

	int sourcePort(atoi(argv[1]));

	int destPort(atoi(argv[2]));

	int destPortConfig(atoi(argv[3]));

	std::string destIp(argv[4]);

	int mediaPort(atoi(argv[5]));

	std::string file(argv[6]);

	Server server(sourcePort,destPort,destPortConfig,destIp,mediaPort,file);

	server.init();

	server.start();

	return 0;
}

