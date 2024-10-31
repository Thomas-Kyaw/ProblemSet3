cmake_minimum_required(VERSION 3.29)
project(ProblemSet3)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProblemSet3 main.cpp
        Character.cpp
        Character.h
        SkillNode.cpp
        SkillNode.h
        SkillList.cpp
        SkillList.h)
