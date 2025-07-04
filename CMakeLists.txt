cmake_minimum_required(VERSION 3.10)
project(ECS)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(REG_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(REG_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## LIBS ##########
add_subdirectory(SparseArray)
add_subdirectory(maths)

########## ECS ##########
add_library( ${PROJECT_NAME} STATIC
    ${REG_SRC_DIR}Registry.cpp
)

target_link_libraries( ${PROJECT_NAME}
    PRIVATE
        sparray
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${REG_HDR_DIR}
)