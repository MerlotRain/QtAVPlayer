cmake_minimum_required(VERSION 3.10)
project(QtAVPlayer)

find_package(FFmpeg REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Widgets Multimidea Multimideawidgets REQUIRED)