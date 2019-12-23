cmake_minimum_required(VERSION 3.15)
project(projectFly)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectFly main.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h ConnectedCommand.cpp ConnectedCommand.h Var.cpp Var.h Print.cpp Print.h Sleep.cpp Sleep.h)