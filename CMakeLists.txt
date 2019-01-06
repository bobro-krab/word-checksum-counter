cmake_minimum_required(VERSION 3.6)
project(counter)
set(CMAKE_CXX_STANDARD 17)

add_executable(prog src/main.cpp)

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE "third-party/catch2")

enable_testing()
add_executable(tests tests/test.cpp tests/catch-main.cpp)
target_include_directories(tests PRIVATE "src")
target_link_libraries(tests Catch2)
add_test(tests tests)
