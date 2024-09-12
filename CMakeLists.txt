cmake_minimum_required(VERSION 3.10)
project(QtAVPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ffmpeg REQUIRED IMPORTED_TARGET libavformat libavdevice libavcodec libavutil libavfilter libswscale libswresample) 

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

if(APPLE)
    find_library(IOSURFACE_LIBRARY IOSurface)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    find_library(COREMEDIA_LIBRARY CoreMedia)
    find_library(METAL_LIBRARY Metal)
    find_library(METAL_FOUNDATION Foundation)
    set(QtAVPlayer_LIBS
        ${QtAVPlayer_LIBS}
        ${IOSURFACE_LIBRARY}
        ${COREVIDEO_LIBRARY}
        ${COREMEDIA_LIBRARY}
        ${METAL_LIBRARY}
        ${METAL_FOUNDATION}
    )
endif()

add_definitions(-DQT_AVPLAYER_MULTIMEDIA)
add_subdirectory(QtAVPlayer)

add_executable(QtAV WIN32 main.cpp qtav.cpp qtav.h)
target_link_libraries(QtAV 
    QtAVPlayer
    ${FFMPEG_LIBRARIES}
    ${QT_VERSION_BASE}::MultimediaWidgets
)

if(APPLE)
        target_link_libraries(QtAV ${QtAVPlayer_LIBS})
endif()