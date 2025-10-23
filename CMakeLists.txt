cmake_minimum_required(VERSION 4.0)
project(CISC220_Binary_Search_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CISC220_Binary_Search_Tree
        BST.cpp
        BST.hpp
        EndangeredSpeciesmain.cpp
        Interface.cpp
        Interface.hpp
        Species.cpp
        Species.hpp
        TNode.cpp
        TNode.hpp)
