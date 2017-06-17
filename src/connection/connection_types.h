/*
 * common.h
 *
 *  Created on: 29 Sep 2016
 *      Author: Oscar Crespo
 */

#ifndef SRC_CONNECTION_CONNECTION_TYPES_H_
#define SRC_CONNECTION_CONNECTION_TYPES_H_

#include <errno.h>
#include <cinttypes>
#include <netinet/in.h>

class Socket;

namespace connection{



struct SConnection
{
public:
    SConnection();
    SConnection(const SConnection &obj);
    SConnection& operator=(const SConnection &rhs);

private:
    struct sockaddr_in connectionInfo_;

    int connection_;

    friend class ::Socket;
};


enum class ESocketType : std::int8_t
{
    STREAM = SOCK_STREAM, // Provides sequenced, reliable, two-way, connection-based byte streams. An out-of-band data transmission mechanism may be supported.
    DGRAM = SOCK_DGRAM, // Supports datagrams (connectionless, unreliable messages of a fixed maximum length).
    SEQPACKET = SOCK_SEQPACKET //Provides a sequenced, reliable, two-way connection-based data transmission path for datagrams of fixed maximum length; a consumer is required to read an entire packet with each input system call.
};

enum class EConnexionType : std::int8_t
{
    IP4 = AF_INET, //IPv4 Internet protocols
    IP6 = AF_INET6 //IPv6 Internet protocols
};

enum class EMessageReceiveType : int
{
    MESSAGE_PEEK = MSG_PEEK,            // Peeks at an incoming message. The data is treated as unread and the next recv() or similar function shall still return this data.
    MESSAGE_OOB = MSG_OOB,              // Requests out-of-band data. The significance and semantics of out-of-band data are protocol-specific.
    MESSAGE_WAITALL = MSG_WAITALL       // On SOCK_STREAM sockets this requests that the function block until the full amount of data can be returned. The function may return the smaller amount of data if the socket is a message-based socket, if a signal is caught, if the connection is terminated, if MSG_PEEK was specified, or if an error is pending for the socket.
};

enum class EMessageSendType : int
{
    MESSAGE_EOR = MSG_EOR,                        // Terminates a record (if supported by the protocol).
    MESSAGE_OOB = MSG_OOB,                        // Sends out-of-band data on sockets that support out-of-band communications. The significance and semantics of out-of-band data are protocol-specific.
    MESSAGE_NOSIGNAL = MSG_NOSIGNAL               // Requests not to send the SIGPIPE signal if an attempt to send is made on a stream-oriented socket that is no longer connected. The [EPIPE] error shall still be returned.
};

enum class ECloseType : int
{
    STOP_RECEIVE = 0,
    STOP_SEND = 1,
    STOP_ALL = 2
};

enum class EError
{
    ACCES,                      // Permission
    ADDRINUSE,                  // The specified address is already in use
    ADDRNOTAVAIL,               // The specified address is  not  available
    BADF,                       // is not a valid descriptor.
    FAULT,                      // The name parameter is  not  in  a  valid part of the user address space.
    INVAL,                      // namelen is  not  the  size  of  a  valid address  for  the specified address family or The  socket  is  already  bound
    NOTSOCK,                    // s is a descriptor  for  a  file,  not  a socket.
    IO,                         // An I/O error o
    ISDIR,                      //  A null path name was specified.
    LOOP,                       // Too many symbolic links were encountered
    NAMETOOLONG,                // The length of the path argument  exceeds
    NOENT,                      // A component of the path  prefix  of  the path name in name does not exist.
    NOTDIR,                     // A component of the path  prefix  of  the path name in name is not a directory.
    ROFS,                       // The inode would reside  on  a  read-only file system.
    MFILE,                      // The  per-process  descriptor  table   is full.
    NFILE,                      // The system file table is full.
    NOBUFS,                     // Insufficient buffer space is  available.
    PROTONOSUPPORT,             // The protocol is  not  supported within  this domain.
    PROTOTYPE,                  // The protocol is the wrong type  for  the socket.
    OPNOTSUPP,                  // The socket is not of a  type  that  supports listen().
    AGAIN,                      // The socket's file descriptor is marked O_NONBLOCK and no data is waiting to be received; or MSG_OOB is set and no out-of-band data is available and either the socket's file descriptor is marked O_NONBLOCK or the socket does not support blocking to await out-of-band data.
    CONNRESET,                  // A connection was forcibly closed by a peer.
    INTR,                       // The function() function was interrupted by a signal that was caught, before any data was available.
    NOTCONN,                    // A receive is attempted on a connection-mode socket that is not connected.
    TIMEDOUT,                   // The connection timed out during connection establishment, or due to a transmission timeout on active connection.
    NOMEM,                      // Insufficient memory was available to fulfill the request.
    DESTADDRREQ,                // The socket is not connection-mode and no peer address is set.
    MSGSIZE,                    // The message is too large to be sent all at once, as the socket requires.
    PIPE,                       // The socket is shut down for writing, or the socket is connection-mode and is no longer connected. In the latter case, and if the socket is of type SOCK_STREAM or SOCK_SEQPACKET and the MSG_NOSIGNAL flag is not set, the SIGPIPE signal is generated to the calling thread.
    NETDOWN,                    // The local network interface used to reach the destination is down.
    NETUNREACH,                 // No route to the network is present.
    UNKNOWN,
    NO_ERROR
};

}


#endif /* SRC_CONNECTION_CONNECTION_TYPES_H_ */
