cmake_minimum_required(VERSION 3.0..3.24)
project(pencil)

include(pencil.cmake)

add_subdirectory(app)
add_subdirectory(core)

add_definitions(app core)