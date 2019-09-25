cmake_minimum_required(VERSION 3.14)
project(tcpClientServer C)

set(CMAKE_C_STANDARD 11)

add_executable(tcpClientServer main.c tcpServer/tcpServer.h includes.h tcpClient/tcpClient.h tcpClient/clientDemo.c tcpServer/serverDemo.c)