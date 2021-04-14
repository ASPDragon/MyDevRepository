cmake_minimum_required(VERSION 3.0.0)
project(lesson_13_3_wt VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(geek_c)

add_executable(lesson_13_3_wt lesson_13_3_wt.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

target_link_libraries(lesson_13_3_wt PUBLIC geek_c)

target_include_directories(lesson_13_3_wt PUBLIC
    "${PROJECT_BINARI_DIR}"
    "${PROJECT_SOURCE_DISR}/geek_c"
)

include(CPack)
