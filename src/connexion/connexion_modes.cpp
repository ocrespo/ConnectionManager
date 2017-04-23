/*
 * connexion_modes.cpp
 *
 *  Created on: 4 Oct 2016
 *      Author: Oscar Crespo
 */

#include "connexion_modes.h"
#include "types.h"

CConnexionBase::CConnexionBase()
{

}

CConnexionBase::CConnexionBase(const CConnexionBase & con):
        socketInterface_{con.socketInterface_}
{

}
CConnexionBase::~CConnexionBase()
{
    socketInterface_.close_socket();
}

CConnexionBase& CConnexionBase::operator=(const CConnexionBase &rhs)
{
    if(this == &rhs) return *this;

    socketInterface_ = rhs.socketInterface_;



    return *this;
}


CConnexionUDP::CConnexionUDP():
        CConnexionBase()
{
    socketInterface_.set_socket_info(EConnexionType::IP4,0,INADDR_ANY);
    socketInterface_.create_socket(ESocketType::DGRAM,EConnexionType::IP4);
}
CConnexionUDP::CConnexionUDP(uint16_t port):
        CConnexionBase()
{
    socketInterface_.set_socket_info(EConnexionType::IP4,port,INADDR_ANY);
    socketInterface_.create_socket(ESocketType::DGRAM,EConnexionType::IP4);
}
CConnexionUDP::CConnexionUDP(uint16_t port,uint32_t address):
        CConnexionBase()
{
    socketInterface_.set_socket_info(EConnexionType::IP4,port,address);
    socketInterface_.create_socket(ESocketType::DGRAM,EConnexionType::IP4);
}
CConnexionUDP::CConnexionUDP(const CConnexionUDP & con):
        CConnexionBase(con)
{

}

CConnexionUDP::~CConnexionUDP()
{

}

CConnexionUDP& CConnexionUDP::operator=(const CConnexionUDP &rhs)
{
    if(this == &rhs) return *this;

    CConnexionBase::operator =(rhs);

    return *this;
}

EError CConnexionUDP::bind()
{
    return socketInterface_.bind_socket();
}

EError CConnexionUDP::send(const uint8_t *buffer,int size, int &sizeSent)
{
    return socketInterface_.send_to_message(socketInterface_,buffer,size,sizeSent);
}

EError CConnexionUDP::receive(uint8_t *buffer,int size, int &sizeReceived)
{
    return socketInterface_.recceive_from_message(socketInterface_,buffer,size,sizeReceived,0);
}

EError CConnexionUDP::disconnect()
{
    return socketInterface_.close_socket();
}






CConnexionTCP::CConnexionTCP():
        CConnexionBase()
{
    socketInterface_.set_socket_info(EConnexionType::IP4,0,INADDR_ANY);
        socketInterface_.create_socket(ESocketType::STREAM,EConnexionType::IP4);
}
CConnexionTCP::CConnexionTCP(uint16_t port):
        CConnexionBase()
{
    socketInterface_.set_socket_info(EConnexionType::IP4,port,INADDR_ANY);
        socketInterface_.create_socket(ESocketType::STREAM,EConnexionType::IP4);
}
CConnexionTCP::CConnexionTCP(uint16_t port,uint32_t address):
        CConnexionBase()
{
    socketInterface_.set_socket_info(EConnexionType::IP4,port,address);
    socketInterface_.create_socket(ESocketType::STREAM,EConnexionType::IP4);
}
CConnexionTCP::CConnexionTCP(const CConnexionTCP & con):
        CConnexionBase(con)
{

}

CConnexionTCP::~CConnexionTCP()
{

}

EError CConnexionTCP::bind()
{
    return socketInterface_.bind_socket();
}

EError CConnexionTCP::connect(struct SConnexion &connection)
{
    return socketInterface_.connect_to(connection);
}

EError CConnexionTCP::wait_connexions()
{
    return socketInterface_.listen_socket();
}
EError CConnexionTCP::accept_connexion(struct SConnexion &connection)
{
    return socketInterface_.accept_connexion(connection);
}
EError CConnexionTCP::send(const struct SConnexion &connection,const uint8_t *buffer,int size, int &sizeSent)
{
    return socketInterface_.send_message(connection,buffer,size,sizeSent,0);
}

EError CConnexionTCP::receive(const struct SConnexion &connection,uint8_t *buffer,int size, int &sizeReceived)
{
    return socketInterface_.recceive_message(connection,buffer,size,sizeReceived,0);
}

EError CConnexionTCP::disconnect()
{
    return socketInterface_.disconnect_socket();
}

CConnexionTCP& CConnexionTCP::operator=(const CConnexionTCP &rhs)
{
    if(this == &rhs) return *this;

    CConnexionBase::operator =(rhs);

    return *this;
}
