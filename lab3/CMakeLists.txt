cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

add_executable(lab3 main.cpp
               MainWindow.cpp MainWindow.hpp
               tasks/TaskWidget.cpp tasks/TaskWidget.hpp
               )

target_link_libraries(lab3 Qt5::Widgets)