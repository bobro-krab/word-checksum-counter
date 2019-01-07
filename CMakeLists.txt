cmake_minimum_required(VERSION 3.6)
project(counter)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES src/u32word.cpp)

add_executable(prog src/main.cpp ${SOURCE_FILES})

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE "third-party/catch2")

enable_testing()
add_executable(tests ${SOURCE_FILES} tests/test.cpp tests/catch-main.cpp)
target_include_directories(tests PRIVATE "src")
target_link_libraries(tests Catch2)
add_test(tests tests)
