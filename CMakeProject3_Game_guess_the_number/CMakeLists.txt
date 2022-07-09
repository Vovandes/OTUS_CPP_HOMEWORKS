cmake_minimum_required(VERSION 3.5)

project(CMakeProject3_Game_guess_the_number)

add_executable(CMakeProject3_Game_guess_the_number
        "main.cpp"
        "argument.h"
        "argument.cpp")

target_compile_features(CMakeProject3_Game_guess_the_number PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(CMakeProject3_Game_guess_the_number PUBLIC /W3 /WX)
else()
    target_compile_options(CMakeProject3_Game_guess_the_number PUBLIC -Wall -Wextra -Werror -pedantic)
endif()