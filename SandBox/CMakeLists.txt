cmake_minimum_required(VERSION 3.29.3)
project(
    SandBox
    VERSION 0.1.0
    LANGUAGES CXX)

file(GLOB SOURCES
"src/*.cpp"
"headers/*.h"
)

add_executable(SandBox
    main.cpp
    ${SOURCES}
)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set_target_properties(SandBox
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
set_property(TARGET SandBox PROPERTY CXX_STANDARD 23)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
