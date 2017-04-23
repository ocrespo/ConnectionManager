/*
 * ConnectionTCPs.h
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#ifndef SRC_CONNEXION_CONNECTIONTCP_H_
#define SRC_CONNEXION_CONNECTIONTCP_H_

#include "ConnectionBase.h"

class ConnectionTCP : ConnectionBase
{
public:

    ConnectionTCP();
    ConnectionTCP(uint16_t port);
    ConnectionTCP(uint16_t port,uint32_t address);
    ConnectionTCP(const ConnectionTCP & con);
    virtual ~ConnectionTCP();

    virtual EError bind() override;

    virtual EError connect(struct SConnexion &connection) override;

    virtual EError wait_connexions() override;

    virtual EError accept_connexion(struct SConnexion &connection) override;

    virtual EError send(const struct SConnexion &connection,const uint8_t *buffer,int size, int &sizeSent) override;

    virtual EError receive(const struct SConnexion &connection,uint8_t *buffer,int size, int &sizeReceived) override;

    virtual EError disconnect() override;


protected:

private:

};

#endif /* SRC_CONNEXION_CONNECTIONTCP_H_ */
