/*
 * ConnectionTCPs.cpp
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#include "ConnectionTCP.h"

#include "ConnectionManager_types.h"

#include "socket_interface.h"


ConnectionTCP::ConnectionTCP():
ConnectionBase()
{
    socketInterface_->set_socket_info(EConnexionType::IP4,0,INADDR_ANY);
    socketInterface_->create_socket(ESocketType::STREAM,EConnexionType::IP4);
}
ConnectionTCP::ConnectionTCP(uint16_t port):
		ConnectionBase()
{
    socketInterface_->set_socket_info(EConnexionType::IP4,port,INADDR_ANY);
	socketInterface_->create_socket(ESocketType::STREAM,EConnexionType::IP4);
}
ConnectionTCP::ConnectionTCP(uint16_t port,uint32_t address):
		ConnectionBase()
{
    socketInterface_->set_socket_info(EConnexionType::IP4,port,address);
    socketInterface_->create_socket(ESocketType::STREAM,EConnexionType::IP4);
}
ConnectionTCP::ConnectionTCP(const ConnectionTCP & con):
		ConnectionBase(con)
{

}

ConnectionTCP::~ConnectionTCP()
{

}

EError ConnectionTCP::bind()
{
    return socketInterface_->bind_socket();
}

EError ConnectionTCP::connect(struct SConnection &connection)
{
    return socketInterface_->connect_to(connection);
}

EError ConnectionTCP::wait_connexions()
{
    return socketInterface_->listen_socket();
}
EError ConnectionTCP::accept_connexion(struct SConnection &connection)
{
    return socketInterface_->accept_connexion(connection);
}
EError ConnectionTCP::send(const struct SConnection &connection,const uint8_t *buffer,int size, int &sizeSent)
{
    return socketInterface_->send_message(connection,buffer,size,sizeSent,0);
}

EError ConnectionTCP::receive(const struct SConnection &connection,uint8_t *buffer,int size, int &sizeReceived)
{
    return socketInterface_->recceive_message(connection,buffer,size,sizeReceived,0);
}

EError ConnectionTCP::disconnect()
{
    return socketInterface_->disconnect_socket();
}


