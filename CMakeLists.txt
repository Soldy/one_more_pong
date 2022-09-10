project(one_more_pong
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/Soldy/one_more_pong"
)
cmake_minimum_required(VERSION 3.18)
add_compile_options(-pthread)
set_property(GLOBAL PROPERTY CXX_STANDARD 20)
add_library(pong_include INTERFACE)
target_include_directories(pong_include INTERFACE include)
target_include_directories(pong_include INTERFACE pthread)
find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(pong main.cpp)
target_link_libraries(pong PUBLIC pong_include ${SDL2_LIBRARIES} ${CURSES_LIBRARIES})

