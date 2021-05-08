cmake_minimum_required(VERSION 3.14)
project(vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES vector/main.cpp vector/Vector.cpp vector/Vector.h _kernel/collection_interfaces/ICollection.h _kernel/collection_interfaces/IEnumerator.h _kernel/collection_interfaces/IEnumerable.h dynamic_array/DynamicArray.cpp dynamic_array/DynamicArray.h)
add_executable(vector ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(vector sfml-system sfml-window sfml-graphics sfml-audio sfml-network)