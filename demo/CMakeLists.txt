cmake_minimum_required(VERSION 3.10)
project(demo)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(DEMO_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(DEMO_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## SFML ##########
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

########## ECS ##########
include_directories("../include")
link_directories("../")

########## BINARY ##########
add_executable( ${PROJECT_NAME}
    ${DEMO_SRC_DIR}main.cpp
)

########## LINKAGE ##########
target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${DEMO_HDR_DIR}
)

target_link_libraries( ${PROJECT_NAME}
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system
    ECS.a
)
