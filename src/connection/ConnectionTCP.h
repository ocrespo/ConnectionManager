/*
 * ConnectionTCPs.h
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#ifndef CONNECTIONTCP_H_
#define CONNECTIONTCP_H_

#include "ConnectionBase.h"

namespace connection{
	class ConnectionTCP;
}


class connection::ConnectionTCP : connection::ConnectionBase
{
public:

    ConnectionTCP();
    ConnectionTCP(uint16_t port);
    ConnectionTCP(uint16_t port,uint32_t address);
    ConnectionTCP(uint16_t port,const char* address);
    ConnectionTCP(const ConnectionTCP & con);
    virtual ~ConnectionTCP();

    virtual connection::EError bind() override;

    virtual connection::EError connect() override;

    virtual connection::EError wait_connections() override;

    virtual connection::EError accept_connection(struct SConnection &connection) override;

    virtual connection::EError send(const uint8_t *buffer,int size, int &sizeSent) override;

    virtual connection::EError send(const struct SConnection &connection,const uint8_t *buffer,int size, int &sizeSent) override;

    virtual connection::EError receive(uint8_t *buffer,int size, int &sizeReceived) override;

    virtual connection::EError receive(struct SConnection &connection,uint8_t *buffer,int size, int &sizeReceived) override;

    virtual connection::EError close_connection(const SConnection &connection,connection::ECloseType close) override;

    virtual connection::EError disconnect() override;


protected:

private:

};

#endif /* SRC_CONNECTION_CONNECTIONTCP_H_ */
