/*
 * ConnectionUDPs->cpp
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#include "ConnectionUDP.h"

#include "connection_types.h"
#include "socket_interface.h"

using connection::EError;
using connection::ConnectionUDP;

ConnectionUDP::ConnectionUDP():
ConnectionBase()
{
    socketInterface_->set_socket_info(EConnexionType::IP4,0,INADDR_ANY);
    socketInterface_->create_socket(ESocketType::DGRAM,EConnexionType::IP4);
}
ConnectionUDP::ConnectionUDP(uint16_t port):
		ConnectionBase()
{
    socketInterface_->set_socket_info(EConnexionType::IP4,port,INADDR_ANY);
    socketInterface_->create_socket(ESocketType::DGRAM,EConnexionType::IP4);
}
ConnectionUDP::ConnectionUDP(uint16_t port,uint32_t address):
		ConnectionBase()
{
    socketInterface_->set_socket_info(EConnexionType::IP4,port,address);
    socketInterface_->create_socket(ESocketType::DGRAM,EConnexionType::IP4);
}
ConnectionUDP::ConnectionUDP(const ConnectionUDP & con):
		ConnectionBase(con)
{

}

ConnectionUDP::~ConnectionUDP()
{

}


EError ConnectionUDP::bind()
{
    return socketInterface_->bind_socket();
}

EError ConnectionUDP::send(const uint8_t *buffer,int size, int &sizeSent)
{
    return socketInterface_->send_to_message(*socketInterface_,buffer,size,sizeSent);
}

EError ConnectionUDP::receive(uint8_t *buffer,int size, int &sizeReceived)
{
    return socketInterface_->recceive_from_message(*socketInterface_,buffer,size,sizeReceived,0);
}

EError ConnectionUDP::disconnect()
{
    return socketInterface_->close_socket();
}

