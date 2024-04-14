cmake_minimum_required(VERSION 3.28)
project(pdf_order)

set(CMAKE_CXX_STANDARD 26)

add_executable(pdf_order main.cpp
        file_utils.h
        file_utils.cpp
        gtk_gui.h
        gtk_gui.cpp)

# Find GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})

target_link_libraries(pdf_order ${GTK3_LIBRARIES}) # Link against GTK libraries
