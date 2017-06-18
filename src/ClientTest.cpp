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
	connection::ConnectionTCP tcp(15731,"127.0.0.1");


	connection::EError error = tcp.connect();
	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR connect " <<std::endl;
	}

	std::string msg{"Hello world"};

	int sent{0};

	error = tcp.send((const uint8_t*)msg.c_str(),256,sent);

	tcp.disconnect();


	return 0;
}
