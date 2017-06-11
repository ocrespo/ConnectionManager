/*
 * ConnectionBase.cpp
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#include "../connection/ConnectionBase.h"

#include "socket_interface.h"

ConnectionBase::ConnectionBase():
			socketInterface_{new Socket()}
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

ConnectionBase& ConnectionBase::operator=(const ConnectionBase &rhs)
{
    if(this == &rhs) return *this;

    socketInterface_ = rhs.socketInterface_;



    return *this;
}
