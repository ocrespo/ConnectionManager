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
    socketInterface_->create_socket(ESocketType::DGRAM,EConnectionType::IP4);
}
ConnectionUDP::ConnectionUDP(uint16_t port):
		ConnectionBase()
{
    socketInterface_->set_connection_info(EConnectionType::IP4,port,INADDR_ANY);
    socketInterface_->create_socket(ESocketType::DGRAM,EConnectionType::IP4);
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

EError ConnectionUDP::send(const connection::SConnection &connection,const uint8_t *buffer,int size, int &sizeSent)
{
    return socketInterface_->send_to_message(connection,buffer,size,sizeSent);
}

EError ConnectionUDP::receive(connection::SConnection &connection,uint8_t *buffer,int size, int &sizeReceived)
{
    return socketInterface_->recceive_from_message(connection,buffer,size,sizeReceived,0);
}

EError ConnectionUDP::disconnect()
{
    return socketInterface_->close_socket();
}

