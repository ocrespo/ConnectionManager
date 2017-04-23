#ifndef __CONNEXION_CONNEXION_H_
#define __CONNEXION_CONNEXION_H_


#include "ConnectionManager_types.h"


namespace connexion
{

    enum class ESocketType;

    enum class EConnexionType;

    enum class EMessageReceiveType;

    enum class EMessageSendType;

    enum class ECloseType;

    enum class EError;

    struct SConnexion;

    class CConnexionBase;

    class CConnexionUDP;

    class CConnexionTCP;
}





#endif
