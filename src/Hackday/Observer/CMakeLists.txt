add_executable(hackServer main.cpp Sernder.cpp Receiver.cpp)
target_link_libraries(hackServer ConnectionManager)
target_include_directories(hackServer PUBLIC release/include)