

set (CONNECTION_SOURCES ${CONNECTION_SOURCES} 
                        ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionBase.cpp 
                        ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionUDP.cpp 
                        ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionTCP.cpp
                        PARENT_SCOPE) #Add .cpp here
set (CONNECTION_HEADERS ${CONNECTION_HEADERS} 
                        ${CMAKE_CURRENT_SOURCE_DIR}/connection_types.h
                         ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionBase.h
                          ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionUDP.h
                           ${CMAKE_CURRENT_SOURCE_DIR}/ConnectionTCP.h
                        PARENT_SCOPE) #Add .h here, just for standalone headers


#add_library(ConnectionManager STATIC ${CONNECTION_SOURCES} ${CONNECTION_HEADERS})
 
#install (TARGETS ConnectionManager DESTINATION release/lib)
#install (FILES ConnectionManager_types.h connection.h DESTINATION release/include)