cmake_minimum_required(VERSION 3.10)

project(WelcomeWebApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(WelcomeWebApp main.cpp)
