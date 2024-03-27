cmake_minimum_required(VERSION 3.28)
project(Viv VERSION 0.1.1 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Viv VivMain.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
