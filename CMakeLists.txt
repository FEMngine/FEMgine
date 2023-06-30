cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/unix")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/unix")

project(femgine LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17 REQUIRED)

set(INCLUDES "include")
message(${INCLUDES})
set(SOURCES "src")
set(TESTS "tutorials")
set(UTILS "utilities")

include_directories(${INCLUDES})

#find_package(to-be-added-later REQUIRED)
#if (to-be-added-later)
#    include_directories(to-be-added-later)
#else()
#    message("Error: failed to locate to-be-added-later")
#endif()

add_library(femgine STATIC 
${UTILS}/items/Entity.cpp
${UTILS}/items/EntityList.cpp
${SOURCES}/geometry/Point.cpp
${UTILS}/items/DOF.cpp
${SOURCES}/geometry/Line.cpp
${SOURCES}/geometry/Surface.cpp
${SOURCES}/geometry/Shape.cpp
${SOURCES}/geometry/Mesh.cpp
${UTILS}/interface/MeshReader.cpp
${UTILS}/interface/GidReader.cpp
${SOURCES}/elements/Element.cpp
${SOURCES}/elements/Lagrange.cpp
${SOURCES}/elements/Nedelec.cpp
)

set_target_properties(femgine
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
)
target_include_directories(femgine PUBLIC ${INCLUDES})

#set(DEPENDENCIES to-be-added-later)

add_executable(test ${TESTS}/test/test.cpp)
include_directories(test ${INCLUDES})
target_link_libraries(test femgine ${DEPENDENCIES})