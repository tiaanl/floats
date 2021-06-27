cmake_minimum_required(VERSION 3.17)

if (TARGET floats)
    return()
endif ()

project(floats)

add_subdirectory(../nucleus nucleus)

include(${nucleus_SOURCE_DIR}/cmake/Utils.cmake)

set(HEADER_FILES
    include/floats/angle.h
    include/floats/common.h
    include/floats/intersection.h
    include/floats/mat3.h
    include/floats/mat4.h
    include/floats/plane.h
    include/floats/pos.h
    include/floats/quaternion.h
    include/floats/random.h
    include/floats/ray.h
    include/floats/rect.h
    include/floats/size.h
    include/floats/transform.h
    include/floats/vec2.h
    include/floats/vec3.h
    include/floats/vec4.h
    )

set(SOURCE_FILES
    src/angle.cpp
    src/mat3.cpp
    src/mat4.cpp
    src/quaternion.cpp
    src/transform.cpp
    src/vec2.cpp
    src/vec3.cpp
    )

nucleus_add_library(floats ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(floats PUBLIC nucleus)

set(TESTS_FILES
    tests/mat4_tests.cpp
    tests/transform_tests.cpp
    tests/vec2_tests.cpp
    tests/vec3_tests.cpp
    tests/vec4_tests.cpp
    )

nucleus_add_executable(floatsTests ${TESTS_FILES})
target_link_libraries(floatsTests PRIVATE floats tests_main)
