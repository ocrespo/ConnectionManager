/*
 * socket_interface.h
 *
 *  Created on: 6 Oct 2016
 *      Author: Oscar Crespo
 */

#ifndef SRC_CONNEXION_SOCKET_INTERFACE_H_
#define SRC_CONNEXION_SOCKET_INTERFACE_H_

#include <netinet/in.h>
#include <cinttypes>


enum class EError;
enum class ESocketType : std::int8_t;
enum class EConnexionType : std::int8_t;
enum class EMessageReceiveType;
enum class EMessageSendType;
enum class ECloseType;

struct SConnexion
{
public:
    SConnexion();
    SConnexion(const SConnexion &obj);
    SConnexion& operator=(const SConnexion &rhs);

private:
    struct sockaddr_in connexionInfo_;

    int connexion_;

    friend class Socket;
};

class Socket
{
public:

    Socket();
    Socket(const Socket &obj);

    ~Socket();

    EError create_socket(ESocketType socketType,EConnexionType connexionType) noexcept;

    void set_socket_info(EConnexionType connexionType,uint16_t port,uint32_t address = INADDR_ANY) noexcept;

    EError bind_socket() noexcept;

    EError listen_socket(int maxConnexions = MAX_CONNEXTION_LISTEN) noexcept;

    EError accept_connexion(SConnexion &connexion) noexcept;

    EError connect_to(SConnexion &connexion) noexcept;

    EError recceive_message(const SConnexion &connexion,uint8_t *buffer,int size,int &sizeRead, int flags) const noexcept;

    EError recceive_from_message(Socket &connexion,uint8_t *buffer,int size,int &sizeRead, int flags) noexcept;

    EError send_message(const SConnexion &connexion,const uint8_t *buffer,int size,int &sizeSent, int flags) const noexcept;

    EError send_to_message(const Socket &connexion,const uint8_t *buffer,int size,int &sizeSent) noexcept;

    EError close_connexion(const SConnexion &connexion,ECloseType close) noexcept;

    EError disconnect_socket() noexcept;

    EError close_socket() noexcept;

    Socket& operator=(const Socket &rhs);


protected:


private:

    static const int MAX_CONNEXTION_LISTEN;

    struct sockaddr_in address_;
    socklen_t size;

    int socketId_;

    EError convert_error() const;

};


#endif /* SRC_CONNEXION_SOCKET_INTERFACE_H_ */
