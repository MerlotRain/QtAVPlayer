cmake_minimum_required(VERSION 3.10)
project(QtAVPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(FFmpeg REQUIRED)

set(BUILD_WITH_QT6 TRUE CACHE BOOL "Enable (experimental) Qt6 support")
if(BUILD_WITH_QT6)
    set(QT_VERSION_MAJOR 6)
    set(QT_MIN_VERSION 6.4.0)
    set(QT_VERSION_BASE "Qt6")
    set(QT_VERSION_BASE_LOWER "qt6")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
    set(QT_VERSION_MAJOR 5)
    set(QT_MIN_VERSION 5.15.2)
    set(QT_VERSION_BASE "Qt5")
    set(QT_VERSION_BASE_LOWER "qt5")
    set(HAS_KDE_QT5_PDF_TRANSFORM_FIX FALSE CACHE BOOL "Using KDE's Qt 5.15 fork with the PDF brush transform fix")
    set(HAS_KDE_QT5_SMALL_CAPS_FIX FALSE CACHE BOOL "Using KDE's Qt 5.15 fork with the QFont stretch fix")
endif()

find_package(${QT_VERSION_BASE} COMPONENTS Core Gui Widgets Multimedia Multimediawidgets REQUIRED)

add_subdirectory(QtAVPlayer)

add_executable(QtAV WIN32 main.cpp)
target_link_libraries(QtAV 
    QtAVPlayer
)