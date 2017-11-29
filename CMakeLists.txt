cmake_minimum_required(VERSION 3.8)
project(Monoplan)

set(CMAKE_C_STANDARD 99)
set(BIN_DIR ${Monoplan_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES main.c Pile/pile.h Pile/pile.c Liste/liste.c Liste/liste.h Cellule/cellule.c Cellule/cellule.h)
add_executable(Monoplan ${SOURCE_FILES})
target_link_libraries(Monoplan m)

add_subdirectory(Pile)
add_subdirectory(Liste)
add_subdirectory(Cellule)