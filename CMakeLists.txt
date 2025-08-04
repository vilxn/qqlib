cmake_minimum_required(VERSION 3.15)
project(qqlib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/libs)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

set(MAIN_FILE main.cpp)

add_executable(main ${MAIN_FILE} ${SRC_FILES} src/glad.o)

link_directories(${CMAKE_SOURCE_DIR}/libs)

target_link_libraries(main
        opengl32
        glfw3
        gdi32
)

add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        $<TARGET_FILE_DIR:main>/shaders)

