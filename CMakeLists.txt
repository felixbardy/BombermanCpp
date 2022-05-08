cmake_minimum_required(VERSION 3.10)
project(BombermanApp VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)


include(CTest)
configure_file(cmake/config/CmakeConfig.h.in ../include/CmakeConfig.h)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/sdl2")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(GTest REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    "include"
)


add_subdirectory(src)
#add_subdirectory(side_programs)
add_subdirectory(test)