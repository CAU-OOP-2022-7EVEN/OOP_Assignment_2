cmake_minimum_required(VERSION 3.23)
project(OOP_Assignment_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@5")
set(CMAKE_PREFIX_PATH  "C:\\Qt\\Qt5.14.2\\5.14.2\\mingw73_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(OOP_Assignment_2 main.cpp inf_int.cpp UIManager.cpp UIManager.h UIManager.cpp UIManager.h QT_UI/mainmenu.cpp QT_UI/mainmenu.h QT_UI/mainmenu.ui resources/resources.qrc)

target_link_libraries(OOP_Assignment_2 Qt5::Widgets)