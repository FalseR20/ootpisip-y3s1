cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

add_executable(lab1 main.cpp MainWindow.cpp MainWindow.hpp ColorChanger.cpp ColorChanger.hpp)
target_link_libraries(lab1 Qt5::Widgets)