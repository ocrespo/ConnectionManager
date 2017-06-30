/*
 * ConnectionBase.h
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#ifndef CONNECTIONBASE_H_
#define CONNECTIONBASE_H_

#include <cinttypes>




class Socket;
namespace connection{
	class ConnectionBase;
	struct SConnection;
	enum class EError;
	enum class ECloseType;

}

class connection::ConnectionBase
{
public:

    virtual ~ConnectionBase();

    virtual connection::EError bind();

    virtual connection::EError connect();

    virtual connection::EError wait_connections();

    virtual connection::EError accept_connection(connection::SConnection &connection);

    virtual connection::EError send(const uint8_t *buffer,int size, int &sizeSent);

    virtual connection::EError send(const connection::SConnection &connection,const uint8_t *buffer,int size, int &sizeSent) ;

    virtual connection::EError receive(uint8_t *buffer,int size, int &sizeReceived);

    virtual connection::EError receive(connection::SConnection &connection,uint8_t *buffer,int size, int &sizeReceived);

    virtual connection::EError close_connection(const SConnection &connection,connection::ECloseType close);

    virtual connection::EError disconnect() = 0;

protected:

    ConnectionBase();
    ConnectionBase(const ConnectionBase & con);

    Socket *socketInterface_;

private:



};

#endif /* SRC_CONNECTION_CONNECTIONBASE_H_ */
