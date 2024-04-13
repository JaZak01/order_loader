cmake_minimum_required(VERSION 3.28)
project(pdf_order)

set(CMAKE_CXX_STANDARD 26)

add_executable(pdf_order main.cpp)

# Find GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(pdf_order ${GTK3_LIBRARIES})