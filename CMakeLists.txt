cmake_minimum_required(VERSION 3.15)
project(fged_vol1_math CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# --- Core math library -------------------------------------------------
# Grows chapter by chapter; every translation unit here corresponds to
# one of the headers in include/. See README.md for the chapter map.
add_library(fged_math STATIC
    src/Vector.cpp
    src/Matrix.cpp
    src/Transform.cpp
    src/Quaternion.cpp
    src/Geometry.cpp
    src/Bivector.cpp
)
target_include_directories(fged_math PUBLIC include)

if(MSVC)
    target_compile_options(fged_math PUBLIC /W4)
else()
    target_compile_options(fged_math PUBLIC -Wall -Wextra)
endif()

# --- Per-chapter playgrounds --------------------------------------------
# One small executable per chapter for working the book's own exercises.
foreach(chapter_num RANGE 1 4)
    set(target_name ch0${chapter_num}_playground)
    add_executable(${target_name} playground/${target_name}.cpp)
    target_link_libraries(${target_name} PRIVATE fged_math)
endforeach()

# --- Tests ---------------------------------------------------------------
enable_testing()
add_executable(fged_tests
    tests/test_main.cpp
    tests/ch01_tests.cpp
    tests/ch02_tests.cpp
    tests/ch03_tests.cpp
    tests/ch04_tests.cpp
)
target_link_libraries(fged_tests PRIVATE fged_math)
target_include_directories(fged_tests PRIVATE tests)

add_test(NAME fged_tests COMMAND fged_tests)
