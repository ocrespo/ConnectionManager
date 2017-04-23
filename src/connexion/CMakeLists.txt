

set (CONNEXION_SOURCES ${CONNEXION_SOURCES} socket_interface.cpp 
                                            ConnectionBase.cpp 
                                            ConnectionUDP.cpp 
                                            ConnectionTCP.cpp) #Add .cpp here
set (CONNEXION_HEADERS ${CONNEXION_HEADERS} connection.h ConnectionManager_types.h) #Add .h here, just for standalone headers


add_library(ConnectionManager STATIC ${CONNEXION_SOURCES} ${CONNEXION_HEADERS})
 
install (TARGETS ConnectionManager DESTINATION release/lib)
install (FILES ConnectionManager_types.h connection.h DESTINATION release/include)