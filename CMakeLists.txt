cmake_minimum_required(VERSION 2.8)

project(SimpleHashTableTemplate)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} "main.cpp" "simplehashtable.cpp" "hashable.cpp" "person.cpp")
