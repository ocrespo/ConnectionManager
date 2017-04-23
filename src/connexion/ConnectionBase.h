/*
 * ConnectionBase.h
 *
 *  Created on: 23 Apr 2017
 *      Author: Oscar Crespo
 */

#ifndef SRC_CONNEXION_CONNECTIONBASE_H_
#define SRC_CONNEXION_CONNECTIONBASE_H_

#include <cinttypes>

enum class EError;

class ConnectionBase
{
public:

    virtual ~ConnectionBase();

    virtual EError bind();

    virtual EError connect(struct SConnexion &connection);

    virtual EError wait_connexions();

    virtual EError accept_connexion(struct SConnexion &connection);

    virtual EError send(const uint8_t *buffer,int size, int &sizeSent);

    virtual EError send(const struct SConnexion &connection,const uint8_t *buffer,int size, int &sizeSent) ;

    virtual EError receive(uint8_t *buffer,int size, int &sizeReceived) = 0;

    virtual EError receive(const struct SConnexion &connection,uint8_t *buffer,int size, int &sizeReceived);

    virtual EError disconnect() = 0;

    virtual ConnectionBase& operator=(const ConnectionBase &rhs);

protected:

    ConnectionBase();
    ConnectionBase(const ConnectionBase & con);

    class Socket *socketInterface_;

private:



};

#endif /* SRC_CONNEXION_CONNECTIONBASE_H_ */
