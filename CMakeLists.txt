cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/unix")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/unix")

project(femgine LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17 REQUIRED)

set(INCLUDES "include")
set(SOURCES "src")
set(TESTS "tutorials")
set(UTILS "utilities")

include_directories(${INCLUDES})

find_package(Eigen3 REQUIRED)
link_directories(${Eigen_INCLUDE_DIRS})

set(DEPENDENCIES ${Eigen_LIBRARIES})

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


enable_testing()

# GTest
include(FetchContent)

FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(unit_gtest ${TESTS}/gtest/gtest.cpp)

target_link_libraries(unit_gtest PRIVATE 
	GTest::GTest
  	femgine
  	${DEPENDENCIES}
)

add_test(gtests unit_gtest)

# Tutorials
add_executable(tutorial_1 ${TESTS}/test/test.cpp)
include_directories(tutorial_1 ${INCLUDES})
target_link_libraries(tutorial_1 femgine ${DEPENDENCIES})