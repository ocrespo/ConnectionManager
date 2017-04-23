/*
 * connexion_modes.h
 *
 *  Created on: 4 Oct 2016
 *      Author: Oscar Crespo
 */

#ifndef SRC_NET_CONNEXION_MODES_H_
#define SRC_NET_CONNEXION_MODES_H_

#include "socket_interface.h"

enum class EError;

class CConnexionBase
{
public:

    virtual ~CConnexionBase();

    virtual EError bind();

    virtual EError connect(struct SConnexion &connection);

    virtual EError wait_connexions();

    virtual EError accept_connexion(struct SConnexion &connection);

    virtual EError send(const uint8_t *buffer,int size, int &sizeSent);

    virtual EError send(const struct SConnexion &connection,const uint8_t *buffer,int size, int &sizeSent) ;

    virtual EError receive(uint8_t *buffer,int size, int &sizeReceived) = 0;

    virtual EError receive(const struct SConnexion &connection,uint8_t *buffer,int size, int &sizeReceived);

    virtual EError disconnect() = 0;

    virtual CConnexionBase& operator=(const CConnexionBase &rhs);

protected:

    CConnexionBase();
    CConnexionBase(const CConnexionBase & con);

    CSocket socketInterface_;

private:



};


class CConnexionUDP : CConnexionBase
{
public:

    CConnexionUDP();
    CConnexionUDP(uint16_t port);
    CConnexionUDP(uint16_t port,uint32_t address);
    CConnexionUDP(const CConnexionUDP & con);
    virtual ~CConnexionUDP();


    virtual EError bind() override;

    virtual EError send(const uint8_t *buffer,int size, int &sizeSent) override;

    virtual EError receive(uint8_t *buffer,int size, int &sizeReceived) override;

    virtual EError disconnect() override;


    virtual CConnexionUDP& operator=(const CConnexionUDP &rhs);

protected:

private:

};

class CConnexionTCP : CConnexionBase
{
public:

    CConnexionTCP();
    CConnexionTCP(uint16_t port);
    CConnexionTCP(uint16_t port,uint32_t address);
    CConnexionTCP(const CConnexionTCP & con);
    virtual ~CConnexionTCP();

    virtual EError bind() override;

    virtual EError connect(struct SConnexion &connection) override;

    virtual EError wait_connexions() override;

    virtual EError accept_connexion(struct SConnexion &connection) override;

    virtual EError send(const struct SConnexion &connection,const uint8_t *buffer,int size, int &sizeSent) override;

    virtual EError receive(const struct SConnexion &connection,uint8_t *buffer,int size, int &sizeReceived) override;

    virtual EError disconnect() override;

    virtual CConnexionTCP& operator=(const CConnexionTCP &rhs);

protected:

private:

};


#endif /* SRC_NET_CONNEXION_MODES_H_ */
