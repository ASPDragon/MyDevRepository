cmake_minimum_required(VERSION 3.16)

project(HW_13 C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(geek_c)

add_executable(lesson_13_HW main.c)

target_link_libraries(lesson_13_HW PUBLIC geek_c)

target_include_directories(lesson_13_HW PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/geek_c"
)