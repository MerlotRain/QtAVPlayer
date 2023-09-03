cmake_minimum_required(VERSION 3.0..3.24)
project(core)
add_library(${PROJECT_NAME} SHARED)

target_compile_definitions(${PROJECT_NAME} PRIVATE CORE_LIBRARY)

find_package(Qt5 COMPONENTS Core Widgets Gui Xml Multimedia Svg Network)

target_sources(${PROJECT_NAME} PRIVATE
        core_global.h

        util/log.cpp
        util/log.h
        util/mathutils.h
        util/movemode.h
        miniz.cpp
        miniz.h)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        Qt5::Xml
        Qt5::Multimedia
        Qt5::Svg
        Qt5::Network)