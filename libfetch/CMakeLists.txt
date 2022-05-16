cmake_minimum_required(VERSION 3.16)
project(libfetch)

option(ENABLE_SSL "enable ssl" OFF)
option(ELABLE_FTP "enable ftp" OFF)

include_directories(include/fetch)

if(${CMAKE_SYSTEM_NAME} STREQUAL "WASI")
    add_definitions(-DMSG_NOSIGNAL=0)
endif()

set(
    fetch_sources
    common.c
    fetch.c
    file.c
    http.c
)

if (ENABLE_SSL)
    add_definitions(-DENABLE_SSL=1)
    list(APPEND ${fetch_sources} openssl_compat.c)
else()
    add_definitions(-DENABLE_SSL=0)
endif()
    
if(ELABLE_FTP)
    add_definitions(-DENABLE_FTP=1)
    list(APPEND ${fetch_sources} ftp.c)
else()
    add_definitions(-DENABLE_FTP=0)
endif()

add_library(
        fetch
        STATIC
        ${fetch_sources}
)

target_include_directories(
    fetch
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
