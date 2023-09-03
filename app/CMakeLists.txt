cmake_minimum_required(VERSION 3.0..3.24)
project(pencil2d)
add_executable(${PROJECT_NAME})

find_package(Qt5 COMPONENTS Core Widgets Gui Xml Multimedia Svg Network)

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
    pencil2d.cpp
    pencil2d.h)

target_link_libraries(${PROJECT_NAME} PRIVATE
Qt5::Core
Qt5::Widgets
Qt5::Gui
Qt5::Xml
Qt5::Multimedia
Qt5::Svg
Qt5::Network)