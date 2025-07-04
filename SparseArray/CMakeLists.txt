project(sparray)

########## SETUP ##########
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(SPAR_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(SPAR_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## LIB ##########
add_library( ${PROJECT_NAME} STATIC
    ${SPAR_SRC_DIR}SparseArray.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${SPAR_HDR_DIR}
)
