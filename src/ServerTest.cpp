/*
 * ServerTest.cpp
 *
 *  Created on: 17 Jun 2017
 *      Author: Oscar Crespo
 */

#include "connection.h"

#include <iostream>

#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(){
	connection::ConnectionTCP tcp(15731);

	connection::EError error{ tcp.bind()};

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR bind "<<  static_cast<std::underlying_type<connection::EError>::type>(error) <<std::endl;
		return -1;
	}

	error = tcp.wait_connexions();

	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR wait " <<std::endl;
	}

	connection::SConnection connection;

	error = tcp.accept_connexion(connection);


	if(error !=  connection::EError::NO_ERROR){
		std::cout<< "ERROR accept_connexion " <<std::endl;
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


	return 0;




	/*int sockfd, newsockfd, portno;
	     socklen_t clilen;
	     char buffer[256];
	     struct sockaddr_in serv_addr, cli_addr;

	     sockfd = socket(AF_INET, SOCK_STREAM, 0);
	     if (sockfd < 0)
	        error("ERROR opening socket");
	     bzero((char *) &serv_addr, sizeof(serv_addr));

	     serv_addr.sin_family = AF_INET;
	     serv_addr.sin_addr.s_addr = INADDR_ANY;
	     serv_addr.sin_port = htons(15731);
	     if (bind(sockfd, (struct sockaddr *) &serv_addr,
	              sizeof(serv_addr)) < 0){
	    	 return -1;
	              error("ERROR on binding");
	     }
	     listen(sockfd,5);
	     clilen = sizeof(cli_addr);
	     newsockfd = accept(sockfd,
	                 (struct sockaddr *) &cli_addr,
	                 &clilen);
	     if (newsockfd < 0)
	          error("ERROR on accept");
	     bzero(buffer,256);

	     close(newsockfd);
	     close(sockfd);
	     return 0;*/
}

