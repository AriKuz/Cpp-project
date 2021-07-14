cmake_minimum_required(VERSION 3.17)
project(projectCPPPart1)

set(CMAKE_CXX_STANDARD 14)

include_directories(projectCPPPart1)

add_executable(projectCPPPart1
        projectCPPPart1/Address.cpp
        projectCPPPart1/Address.h
        projectCPPPart1/Animal.cpp
        projectCPPPart1/Animal.h
        projectCPPPart1/Bat.cpp
        projectCPPPart1/Bat.h
        projectCPPPart1/Bird.cpp
        projectCPPPart1/Bird.h
        projectCPPPart1/Cage.cpp
        projectCPPPart1/Cage.h
        projectCPPPart1/Canfly.cpp
        projectCPPPart1/Canfly.h
        projectCPPPart1/CanSwin.cpp
        projectCPPPart1/CanSwin.h
        projectCPPPart1/Crocodile.cpp
        projectCPPPart1/Crocodile.h
        projectCPPPart1/Employee.cpp
        projectCPPPart1/Employee.h
        projectCPPPart1/Lion.cpp
        projectCPPPart1/Lion.h
        projectCPPPart1/Mammal.cpp
        projectCPPPart1/Mammal.h
        projectCPPPart1/Ostrich.cpp
        projectCPPPart1/Ostrich.h
        projectCPPPart1/Parrot.cpp
        projectCPPPart1/Parrot.h
        projectCPPPart1/projectCPPPart1.cpp
        projectCPPPart1/Reptile.cpp
        projectCPPPart1/Reptile.h
        projectCPPPart1/Zoo.cpp
        projectCPPPart1/Zoo.h projectCPPPart1/MyTemplate.h)
