cmake_minimum_required(VERSION 3.5)

project(CMakeProject1_Hello_World)

add_executable(CMakeProject1_Hello_World 
    "hello_world.cpp"
    "example.cpp"
    "example.h"
    "move_me_out.h" 
    "move_me_out.cpp")

set_target_properties(CMakeProject1_Hello_World PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)