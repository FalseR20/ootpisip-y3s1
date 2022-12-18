cmake_minimum_required(VERSION 3.10)
project(lab7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(lab7
               main.cpp
               mainwindow.cpp mainwindow.h mainwindow.ui
               Snowflake.cpp Snowflake.h
               VerticalText.cpp VerticalText.h)

target_link_libraries(lab7 Qt5::Widgets)