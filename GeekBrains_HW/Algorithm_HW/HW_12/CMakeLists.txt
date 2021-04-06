cmake_minimum_required(VERSION 3.20)

project(lesson_12_HW LANGUAGE C)

set(CMAKE_C_STANDARD C99)

add_subdirectory(geek_c)

add_executable(lesson_12_HW lesson_12_HW.c)

target_link_libraries(lesson_12_HW PUBLIC geek_c)

target_include_directories(lesson_12_HW PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/geek_c"
)