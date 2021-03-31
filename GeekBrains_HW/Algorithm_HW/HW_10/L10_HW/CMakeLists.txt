cmake_minimum_required(VERSION 3.5)

project(L10_HW LANGUAGES C)

add_subdirectory(sources)

add_executable(L10_HW main.c)

target_link_libraries(L10_HW PUBLIC sources)

target_include_directories(L10_HW PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/sources"
    )
