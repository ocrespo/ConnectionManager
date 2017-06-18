/*
 * ServerTest.cpp
 *
 *  Created on: 17 Jun 2017
 *      Author: Oscar Crespo
 */

#include "connection.h"

#include <iostream>

#include <string>


int main(){

	connection::ConnectionUDP udp(15731);

	connection::EError error{ udp.bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind "<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
	}

	connection::SConnection from;

	uint8_t buf[256];

	int received(0);

	while(1){
		udp.receive(from,buf,256,received);

		std::cout<< buf<< " "<<received <<std::endl;

	}

	return 0;
}

void TCP(){

	connection::ConnectionTCP tcp(15731);

	connection::EError error{ tcp.bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind "<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
		return ;
	}

	error = tcp.wait_connections();

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR wait " <<std::endl;
	}

	connection::SConnection connection;

	error = tcp.accept_connection(connection);


	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR accept_connection " <<std::endl;
	}


	uint8_t data[256];
	int received{0};
	error = tcp.receive(connection,data,256,received);


	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR receive " <<std::endl;
	}


	std::cout<< data<< " "<<received <<std::endl;
	//tcp.send(connection,(const uint8_t*)msg.c_str(),sizeof(msg.c_str()),sent);

	tcp.disconnect();

}
