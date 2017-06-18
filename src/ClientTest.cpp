/*
 * ClientTest.cpp
 *
 *  Created on: 17 Jun 2017
 *      Author: Oscar Crespo
 */



#include "connection.h"

#include <string>

#include <iostream>

int main(){
	connection::ConnectionUDP udp;

	connection::EError error{ udp.bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind "<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
	}

	connection::SConnection server(connection::EConnectionType::IP4,15731,"127.0.0.1");

	uint8_t buf[256]="What a party";

	int sent(0);


		udp.send(server,buf,256,sent);

		std::cout<<"Sent "<<sent <<std::endl;



	return 0;
}

void TCP(){

	connection::ConnectionTCP tcp(15731,"127.0.0.1");


	connection::EError error = tcp.connect();
	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR connect " <<std::endl;
	}

	std::string msg{"Hello world"};

	int sent{0};

	error = tcp.send((const uint8_t*)msg.c_str(),256,sent);

	tcp.disconnect();


}
