/*
 * ConnectionBase.cpp
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#include "ConnectionBase.h"

#include "connection_types.h"
#include "socket_interface.h"

using connection::EError;
using connection::SConnection;
using connection::ConnectionBase;

ConnectionBase::ConnectionBase():
			socketInterface_{new Socket}
{

}

ConnectionBase::ConnectionBase(const ConnectionBase& con):
        socketInterface_{new Socket(*con.socketInterface_)}
{

}

ConnectionBase::~ConnectionBase()
{
    socketInterface_->close_socket();
    delete socketInterface_;
}

EError ConnectionBase::bind(){
	return EError::NO_ERROR;
}

EError ConnectionBase::connect(){
	return EError::NO_ERROR;

}

EError ConnectionBase::wait_connections(){
	return EError::NO_ERROR;

}

EError ConnectionBase::accept_connection(struct SConnection &connection){
	return EError::NO_ERROR;

}

EError ConnectionBase::send(const uint8_t *buffer,int size, int &sizeSent){
	return EError::NO_ERROR;
}

EError ConnectionBase::send(const struct SConnection &connection,const uint8_t *buffer,int size, int &sizeSent){
	return EError::NO_ERROR;

}

EError ConnectionBase::receive(uint8_t *buffer,int size, int &sizeReceived){
	return EError::NO_ERROR;
}

EError ConnectionBase::receive(struct SConnection &connection,uint8_t *buffer,int size, int &sizeReceived){
	return EError::NO_ERROR;
}

EError ConnectionBase::close_connection(const SConnection &connection,ECloseType close){
	return EError::NO_ERROR;
}

