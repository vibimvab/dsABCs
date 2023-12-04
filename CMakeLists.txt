cmake_minimum_required(VERSION 3.14)
project(dsABCs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h Word.cpp Word.h Algorithm.cpp)
add_executable(dsABCs ${SOURCE_FILES})
include_directories(/usr/local/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "SFML-2.6.1/lib/cmake/SFML")


find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(dsABCs sfml-system sfml-window sfml-graphics sfml-audio)
