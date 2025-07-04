cmake_minimum_required(VERSION 3.10)
project(demo)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(DEMO_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(DEMO_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

include_directories("../include")
link_directories("../")

include_directories("../SparseArray/include")
link_directories("../SparseArray/")

########## BINARY ##########
add_executable( ${PROJECT_NAME}
    ${DEMO_SRC_DIR}main.cpp
)

########## LINKAGE ##########
target_link_libraries(${PROJECT_NAME}
    sparray.a
    ECS.a
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${DEMO_HDR_DIR}
)
