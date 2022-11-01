cmake_minimum_required(VERSION 3.20)
project(SiAOD5)

set(CMAKE_CXX_STANDARD 23)

add_executable(SiAOD5 main.cpp PhoneUser.hpp PhoneBook.h PhoneBook.cpp PBBTNode.h PBBTNode.cpp DTNode.h DTNode.cpp TNode.h TNode.cpp)
