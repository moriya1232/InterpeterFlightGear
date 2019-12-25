cmake_minimum_required(VERSION 3.15)
project(projectFly)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(projectFly main.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h ConnectedCommand.cpp ConnectedCommand.h Var.cpp Var.h Print.cpp Print.h Sleep.cpp Sleep.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h LoopCommand.cpp LoopCommand.h Expression.h ex1.cpp ex1.h)