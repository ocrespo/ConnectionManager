/*
 * Server.cpp
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#include "Server.h"

#include <functional>

#include <string>
#include <fstream>
#include <iostream>


#include "Receiver.h"
#include "Sender.h"
#include "ServerMedia.h"

Server::Server(int sourcePort,int destPort,int destPortConfig,const std::string& destIp,int mediaPort,const std::string& file) :
		receiver(new Receiver(sourcePort)),
		sender(new Sender(destIp,destPort,destPortConfig,mediaPort)),
		media(new ServerMedia(mediaPort)),
		filename(file)
{

}

Server::~Server() {
	delete receiver;
	delete sender;
}


void Server::init(){

	readFile();
	receiver->registerCallback(std::bind(&Server::newPackage,this,std::placeholders::_1));


}

void Server::readFile(){
	std::ifstream file(filename);
	std::string line;

	if(file.is_open()){

		file.seekg (0, std::ios::end);
		int length (file.tellg());
		file.seekg (0, std::ios::beg);

		char *data (new char[length]);

		file.read(data,length);

		file.close();

		media->assignData((uint8_t*)data,length);
	}
	else{
		std::cout<< "Error opening the file "<<std::endl;
	}
}


void Server::start(){

	media->init();

	sender->init();

	receiver->init();

	while(1);
}

void Server::newPackage(struct sPackage* pkt){
	sender->newPackage(pkt);
}
