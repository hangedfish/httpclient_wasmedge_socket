cmake_minimum_required(VERSION 3.16)

project(wasmedge_wasi_socket_c)

add_library(
    wasmedge_wasi_socket_c
    STATIC
    wasi_socket_ext.c
)

target_include_directories(
    wasmedge_wasi_socket_c
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)