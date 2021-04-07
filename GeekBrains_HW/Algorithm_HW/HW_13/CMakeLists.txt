cmake_minimum_required(VERSION 3.16)

project(lesson_13_HW C)

set(CMAKE_C_FLAGS "-std=c99")

add_subdirectory(geek_c)

add_executable(lesson_13_HW lesson_13_HW.c)

target_link_directories(lesson_13_HW PUBLIC geek_c)

target_include_directories(lesson_13_HW PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/geek_c"
)