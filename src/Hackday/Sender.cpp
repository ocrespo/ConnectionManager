/*
 * Sernder.cpp
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#include "Sender.h"

#include <iostream>
#include <unistd.h>
#include <cstring>

#include "../connection.h"

#include "PackageType.h"

Sender::Sender(std::string ip,int port,int portConfig,int mediaPort) :
		buffer(),
		connection(new connection::ConnectionUDP()),
		connectionInfo(new connection::ConnectionUDP()),
		destIp(ip),
		destPort(port),
		destPortConfig(portConfig),
		sendMediaPort(mediaPort),
		thread(),
		threadConfig(),
		mutex(),
		finish(false)
{

}
Sender::~Sender() {
	end();
	connection->disconnect();
	connectionInfo->disconnect();

	delete connection;
	delete connectionInfo;

	for(auto it = buffer.begin(); it != buffer.end();++it){
		if(*it != nullptr){
			delete *it;
		}
	}
}

void Sender::init(){
	finish = false;



	connection::EError error{ connection->bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind sender"<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
	}


	thread = std::thread(&Sender::sendLoop,this);
	threadConfig = std::thread(&Sender::sendLoopConfig,this);


}

void Sender::end(){
	finish = true;

	thread.join();
}

void Sender::newPackage(sPackage* package){
	mutex.lock();
	buffer.push_back(package);
	mutex.unlock();
}

void Sender::sendLoop(){
	connection::SConnection server(connection::EConnectionType::IP4,destPort,destIp.c_str());

	sPackage *pkt(nullptr);
	int sent(0);


	while(!finish){

		if(!buffer.empty()){

			mutex.lock();
			pkt = buffer.front();
			buffer.pop_front();
			mutex.unlock();

			connection->send(server,pkt->payload,pkt->size,sent);

			delete pkt;
		}
		else{
			usleep(1);
		}

	}
}

void Sender::sendLoopConfig(){

	connection::SConnection serverConfig(connection::EConnectionType::IP4,destPortConfig,destIp.c_str());

	std::string dataConfig("10.2.1.60:");
	//std::string dataConfig("10.2.1.59:");


	dataConfig.append(std::to_string(sendMediaPort));

	int sent(0);

	while(!finish){

		connection->send(serverConfig,(uint8_t*)dataConfig.c_str(),strlen(dataConfig.c_str()),sent);

		sleep(1);

	}
}
