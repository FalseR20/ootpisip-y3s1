cmake_minimum_required(VERSION 3.10)
project(lab8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(lab8
               main.cpp
               mainwindow.cpp mainwindow.h mainwindow.ui
               task1.cpp task1.h
               task2.cpp task2.cpp)

target_link_libraries(lab8 Qt5::Widgets)