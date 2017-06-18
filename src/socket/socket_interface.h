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


namespace  connection{
	struct SConnection;
	enum class EError;
	enum class ESocketType : std::int8_t;
	enum class EConnexionType : std::int8_t;
	enum class ECloseType;
}


class Socket
{
public:

    Socket();
    Socket(const Socket &obj);

    ~Socket();

    connection::EError create_socket(connection::ESocketType socketType,connection::EConnexionType connexionType) noexcept;

    void set_socket_info(connection::EConnexionType connexionType,uint16_t port,uint32_t address = INADDR_ANY) noexcept;

    void set_socket_info(connection::EConnexionType connexionType,uint16_t port,const char* address) noexcept;

    connection::EError bind_socket() noexcept;

    connection::EError listen_socket(int maxConnexions = MAX_CONNEXTION_LISTEN) noexcept;

    connection::EError accept_connexion(connection::SConnection &connexion) noexcept;

    connection::EError connect_to() noexcept;

    connection::EError recceive_message(uint8_t *buffer,int size,int &sizeRead, int flags) const noexcept;

    connection::EError recceive_message(const connection::SConnection &connexion,uint8_t *buffer,int size,int &sizeRead, int flags) const noexcept;

    connection::EError recceive_from_message(connection::SConnection &connexion,uint8_t *buffer,int size,int &sizeRead, int flags) noexcept;

    connection::EError send_message(const uint8_t *buffer,int size,int &sizeSent, int flags)const noexcept;

    connection::EError send_message(const connection::SConnection &connexion,const uint8_t *buffer,int size,int &sizeSent, int flags) const noexcept;

    connection::EError send_to_message(const connection::SConnection &connexion,const uint8_t *buffer,int size,int &sizeSent) noexcept;

    connection::EError close_connexion(const connection::SConnection &connexion,connection::ECloseType close) noexcept;

    connection::EError disconnect_socket() noexcept;

    connection::EError close_socket() noexcept;

    Socket& operator=(const Socket &rhs);


protected:


private:

    static const int MAX_CONNEXTION_LISTEN;

    struct sockaddr_in address_;
    socklen_t size_;

    int socketId_;

    connection::EError convert_error() const;

};


#endif /* SRC_CONNEXION_SOCKET_INTERFACE_H_ */
