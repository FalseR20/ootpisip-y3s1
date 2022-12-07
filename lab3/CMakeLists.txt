cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

add_executable(lab3 main.cpp
               MainWindow.cpp MainWindow.hpp
               tasks/TaskWidget.cpp tasks/TaskWidget.hpp
               tasks/Task1.cpp tasks/Task1.hpp
               tasks/Task2.cpp tasks/Task2.hpp
               tasks/Task3.cpp tasks/Task3.hpp
               tasks/Task4.cpp tasks/Task4.hpp
               tasks/Task5.cpp tasks/Task5.hpp
               tasks/AdditionalTask.cpp tasks/AdditionalTask.hpp
               )

target_link_libraries(lab3 Qt5::Widgets)