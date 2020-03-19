cmake_minimum_required(VERSION 2.8.9)
project(graph)
 
#Bring the headers, such as Student.h into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/Graph.cpp src/module_1.cpp src/module_2.cpp src/module_3.cpp src/module_4.cpp src/module_5.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(graph ${SOURCES})