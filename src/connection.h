#ifndef __CONNEXION_CONNEXION_H_
#define __CONNEXION_CONNEXION_H_


#include "connection/connection_types.h"
#include "connection/ConnectionBase.h"
#include "connection/ConnectionUDP.h"
#include "connection/ConnectionTCP.h"


namespace connection
{

    enum class ESocketType : std::int8_t;

    enum class EConnexionType : std::int8_t;

    enum class EMessageReceiveType;

    enum class EMessageSendType;

    enum class ECloseType;

    enum class EError;

    struct SConnection;

    class ConnectionBase;

    class ConnectionUDP;

    class ConnectionTCP;
}





#endif
