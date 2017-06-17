

#set (CONNECTION_SOURCES ${CONNECTION_SOURCES} socket_interface.cpp 
 #                                           ConnectionBase.cpp 
 #                                           ConnectionUDP.cpp 
 #                                           ConnectionTCP.cpp) #Add .cpp here
set (CONNECTION_HEADERS ${CONNECTION_HEADERS} connection.h ) #Add .h here, just for standalone headers

include_directories(${PROJECT_SOURCE_DIR}/connection
                    ${PROJECT_SOURCE_DIR}/socket)
                    
 
 add_subdirectory(${PROJECT_SOURCE_DIR}/socket)
                   
add_subdirectory(${PROJECT_SOURCE_DIR}/connection)

add_subdirectory(${PROJECT_SOURCE_DIR}/manager)


add_library(ConnectionManager STATIC ${CONNECTION_SOURCES} ${CONNECTION_HEADERS})
 
install (TARGETS ConnectionManager DESTINATION release/lib)
install (FILES ${CONNECTION_HEADERS} DESTINATION release/include)

################## TESTS ############################
add_executable(serverTest ServerTest.cpp)
target_link_libraries(serverTest ConnectionManager)
target_include_directories(serverTest PUBLIC release/include)

add_executable(clientTest ClientTest.cpp)
target_link_libraries(clientTest ConnectionManager)
target_include_directories(clientTest PUBLIC release/include)



