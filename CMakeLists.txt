cmake_minimum_required(VERSION 3.10)
project(ECS)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(ECS_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(ECS_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## SFML ##########
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

########## ECS ##########
add_library( ${PROJECT_NAME} STATIC
    ${ECS_SRC_DIR}Registry.cpp

    # components
    ${ECS_SRC_DIR}components/position.cpp
    ${ECS_SRC_DIR}components/velocity.cpp
    ${ECS_SRC_DIR}components/drawable.cpp
    ${ECS_SRC_DIR}components/sprite.cpp

    # systems
    ${ECS_SRC_DIR}systems/movement.cpp
    ${ECS_SRC_DIR}systems/draw.cpp
    ${ECS_SRC_DIR}systems/controle.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${ECS_HDR_DIR}
)

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system
)
