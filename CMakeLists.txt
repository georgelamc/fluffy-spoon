cmake_minimum_required(VERSION 3.29)
project(fluffy_spoon)

set(CMAKE_CXX_STANDARD 20)
set(OPENSSL_ROOT_DIR "C:/msys64/ucrt64")
set(OPENSSL_INCLUDE_DIR "C:/msys64/ucrt64/include")
set(OPENSSL_LIBRARIES "C:/msys64/ucrt64/lib")

add_executable(fluffy_spoon
        src/main.cpp
        src/Block.cpp
        include/Block.h
        include/HashUtil.h)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(fluffy_spoon ${OPENSSL_LIBRARIES})
