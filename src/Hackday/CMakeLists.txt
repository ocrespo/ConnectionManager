
find_package (Threads)

add_executable(hackServer main.cpp Server.cpp Sender.cpp Receiver.cpp ServerMedia.cpp)
target_link_libraries(hackServer ConnectionManager ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(hackServer PUBLIC release/include)