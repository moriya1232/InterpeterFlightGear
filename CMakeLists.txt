cmake_minimum_required(VERSION 3.15)
project(projectFly)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectFly main.cpp Command.h OpenSeverCommand.cpp OpenSeverCommand.h ConnectedCommand.cpp ConnectedCommand.h Var.cpp Var.h)