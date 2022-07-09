cmake_minimum_required(VERSION 3.8)

project(CMakeProject1_Hello_World CXX)

add_executable(CMakeProject1_Hello_World 
    "hello_world.cpp"
    "example.cpp"
    "example.h"
    "move_me_out.h" 
    "move_me_out.cpp")

target_compile_features(CMakeProject1_Hello_World PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(CMakeProject1_Hello_World PUBLIC /W3 /WX)
else()
    target_compile_options(CMakeProject1_Hello_World PUBLIC -Wall -Wextra -Werror -pedantic)
endif()