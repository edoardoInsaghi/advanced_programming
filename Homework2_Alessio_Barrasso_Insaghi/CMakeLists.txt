cmake_minimum_required(VERSION 3.12)

project(Homework2_Alessio_Barrasso_Insaghi
        VERSION 1.0
        DESCRIPTION "Second homework for the advanced programming course."
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(statsMod SHARED src/statsMod.cpp)
target_include_directories(statsMod PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(main tests/main.cpp)
#target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Link the library to the executable
target_link_libraries(main PRIVATE statsMod)