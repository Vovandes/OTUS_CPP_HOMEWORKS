cmake_minimum_required(VERSION 3.5)

project(CMakeProject3_Game_guess_the_number)

add_executable(CMakeProject3_Game_guess_the_number
        "main.cpp"
        "Gamer.hpp"
        "Gamer.cpp"
        "Files.hpp"
        "Files.cpp"
        "game.hpp"
        "game.cpp"
        "argument.hpp"
        "argument.cpp")

string(REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

target_compile_features(CMakeProject3_Game_guess_the_number PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(CMakeProject3_Game_guess_the_number PUBLIC /W4 /WX)
else()
    target_compile_options(CMakeProject3_Game_guess_the_number PUBLIC -Wall -Wextra -Werror -pedantic)
endif()