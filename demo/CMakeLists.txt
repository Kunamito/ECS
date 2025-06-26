cmake_minimum_required(VERSION 3.10)
project(demo)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(DEMO_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(DEMO_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

set(ECS_LIB "${PROJECT_SOURCE_DIR}/../ECS.a")

########## BINARY ##########
add_executable( ${PROJECT_NAME}
    ${DEMO_SRC_DIR}main.cpp
)

target_link_libraries( ${PROJECT_NAME}
    ECS_LIB
)

########## LINKAGE ##########
target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${DEMO_HDR_DIR}
)
