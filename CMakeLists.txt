cmake_minimum_required(VERSION 3.0..3.24)
project(pencil2D)

include(pencil.cmake)

add_executable(pencil2D WIN32)

find_package(Qt5 COMPONENTS Core Gui Widgets Xml)

target_sources(${PROJECT_NAME} PRIVATE
    app/color/colorbox.cpp
    app/color/colorbox.h
    app/color/colordialog.cpp
    app/color/colordialog.h
    app/color/colorpreviewwidget.cpp
    app/color/colorpreviewwidget.h
    app/color/colorrampwidget.cpp
    app/color/colorrampwidget.h
    app/color/colorsliderwidget.cpp
    app/color/colorsliderwidget.h
    app/color/colortextwidget.cpp
    app/color/colortextwidget.h
    app/color/colorwheel.cpp
    app/color/colorwheel.h
    app/color/colorwidget.cpp
    app/color/colorwidget.h
    app/color/colorwidgetaction.cpp
    app/color/colorwidgetaction.h
    app/aboutdialog.cpp
    app/main.cpp
    app/mainwindow.cpp
    app/mainwindow.h
    app/pencil.cpp
    app/pencil.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Xml
)