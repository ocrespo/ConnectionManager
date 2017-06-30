/*
 * Receiver.cpp
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#include "Receiver.h"

#include <iostream>
#include <string>
#include <unistd.h>


#include "../connection.h"

#include "PackageType.h"


Receiver::Receiver(int port) :
		connection(new connection::ConnectionUDP(port)),
		finish(false),
		thread()
{


}
Receiver::~Receiver() {
	stop();

	connection->disconnect();
	delete connection;
}

void Receiver::registerCallback(const callback_t& callback){
	newPackage_callback = callback;
}

void Receiver::init(){

	finish = false;

	connection::EError error{ connection->bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind receiver"<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
	}

	thread = std::thread(&Receiver::receiveLoop,this);


}

void Receiver::stop(){
	finish = true;

	thread.join();
}

void Receiver::receiveLoop(){


	connection::SConnection from;



	while(!finish){

		sPackage *pkt(new sPackage);

		connection->receive(from,pkt->payload,MTU,pkt->size);
		if(pkt->size == 0){
			usleep(1);
		}
		else{
			newPackage_callback(pkt);
		}
	}

}
