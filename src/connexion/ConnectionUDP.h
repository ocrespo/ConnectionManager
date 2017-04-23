/*
 * ConnectionUDPs.h
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#ifndef SRC_CONNEXION_CONNECTIONUDP_H_
#define SRC_CONNEXION_CONNECTIONUDP_H_

#include "ConnectionBase.h"


class ConnectionUDP : ConnectionBase
{
public:

    ConnectionUDP();
    ConnectionUDP(uint16_t port);
    ConnectionUDP(uint16_t port,uint32_t address);
    ConnectionUDP(const ConnectionUDP & con);
    virtual ~ConnectionUDP();


    virtual EError bind() override;

    virtual EError send(const uint8_t *buffer,int size, int &sizeSent) override;

    virtual EError receive(uint8_t *buffer,int size, int &sizeReceived) override;

    virtual EError disconnect() override;


protected:

private:

};

#endif /* SRC_CONNEXION_CONNECTIONUDP_H_ */
