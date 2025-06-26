cmake_minimum_required(VERSION 3.10)
project(ECS)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## LIB ##########
add_library( ${PROJECT_NAME} STATIC
    ${SRC_DIR}Registry.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${HDR_DIR}
)