set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(tools $ENV{HOME}/x-tools/arm-unknown-linux-gnueabi)

set(CMAKE_SYSROOT ${tools}/arm-unknown-linux-gnueabi/sysroot)
set(CMAKE_STAGING_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})


set(CMAKE_C_COMPILER ${tools}/bin/arm-unknown-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-unknown-linux-gnueabi-g++)


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)