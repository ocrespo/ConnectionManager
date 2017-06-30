/*
 * InteractiveProvider.cpp
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#include "ServerMedia.h"

#include <iostream>

#include "../connection.h"

#include "PackageType.h"

ServerMedia::ServerMedia(int port) :
			connection(new connection::ConnectionTCP(port)),
			thread(),
			finish(false),
			payload(nullptr),
			sizeData(0)
{

}

ServerMedia::~ServerMedia() {
	delete connection;

	if(payload != nullptr){
		delete payload;
	}

	delete[] payload;
}

void ServerMedia::init(){


	connection::EError error{ connection->bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind "<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
		return ;
	}

	thread = std::thread(&ServerMedia::loop,this);
}

void ServerMedia::assignData(uint8_t* data,int length){
	payload = data;
	sizeData = length;
}


void ServerMedia::end(){
	finish = true;

	thread.join();
}


void ServerMedia::loop(){
	connection::EError error(connection::EError::NO_ERROR);

	while(!finish){

		error = connection->wait_connections();

		if(error !=  connection::EError::NO_ERROR){
			std::cout<< "ERROR wait " <<std::endl;
		}

		connection::SConnection client;

		error = connection->accept_connection(client);


		if(error !=  connection::EError::NO_ERROR){
			std::cout<< "ERROR accept_connection " <<std::endl;
		}

		
		int sent{0};
		error = connection->send(client,payload,sizeData,sent);
		if(sent < sizeData){
			int rest (sizeData - sent);
			while(rest > 0){
				error = connection->send(client,&payload[rest-1],rest,sent);
				rest = rest - sent;
			}
		}



		std::cout<<sent <<std::endl;
		//tcp.send(connection,(const uint8_t*)msg.c_str(),sizeof(msg.c_str()),sent);

		connection->close_connection(client,connection::ECloseType::STOP_ALL);

	}

	connection->disconnect();
}
