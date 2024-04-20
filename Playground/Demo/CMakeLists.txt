cmake_minimum_required(VERSION 3.28.0)
project(BootCamp VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(BootCamp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
