project(one_more_pong
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/Soldy/one_more_pong"
)
cmake_minimum_required(VERSION 3.18)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
set_property(GLOBAL PROPERTY CXX_STANDARD 20)
add_library(pong_include INTERFACE)
target_include_directories(pong_include INTERFACE include)
target_include_directories(pong_include INTERFACE pthread)
#find_package(Curses REQUIRED)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
add_executable(pong main.cpp)
target_link_libraries(pong PUBLIC pong_include SDL2 SDL2_image SDL2_ttf SDL2_mixer)

