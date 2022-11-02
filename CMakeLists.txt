cmake_minimum_required(VERSION 3.23)
project(OOP_Assignment_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@5")

find_package(Qt5Widgets REQUIRED)

add_executable(OOP_Assignment_2 main.cpp inf_int.cpp)

target_link_libraries(OOP_Assignment_2 Qt5::Widgets)