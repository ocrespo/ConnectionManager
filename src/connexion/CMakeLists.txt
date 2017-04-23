

set (CONNEXION_SOURCES ${CONNEXION_SOURCES} connexion.cpp socket_interface.cpp connexion_modes.cpp) #Add .cpp here
set (CONNEXION_HEADERS ${CONNEXION_HEADERS} types.h) #Add .h here, just for standalone headers


add_library(ConnectionManager STATIC ${CONNEXION_SOURCES} ${CONNEXION_HEADERS})
 
install (TARGETS ConnectionManager DESTINATION release/lib)
install (FILES types.h DESTINATION release/include)