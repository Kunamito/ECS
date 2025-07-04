project(maths)

########## SETUP ##########
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../)
set(MAT_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(MAT_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## LIB ##########
add_library( ${PROJECT_NAME} STATIC
    ${MAT_SRC_DIR}maths.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${MAT_HDR_DIR}
)
