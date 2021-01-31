cmake_minimum_required(VERSION 3.17)

project(floats)

add_subdirectory(../nucleus nucleus)

include(${nucleus_SOURCE_DIR}/cmake/Utils.cmake)

set(HEADER_FILES
    include/floats/Angle.h
    include/floats/Common.h
    include/floats/Intersection.h
    include/floats/Mat3.h
    include/floats/Mat4.h
    include/floats/Plane.h
    include/floats/Pos.h
    include/floats/Quaternion.h
    include/floats/Ray.h
    include/floats/Rect.h
    include/floats/Size.h
    include/floats/Transform.h
    include/floats/Vec2.h
    include/floats/Vec3.h
    include/floats/Vec4.h
    )

set(SOURCE_FILES
    src/Angle.cpp
    src/Mat3.cpp
    src/Mat4.cpp
    src/Quaternion.cpp
    src/Transform.cpp
    src/Vec2.cpp
    src/Vec3.cpp
    )

nucleus_add_library(floats ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(floats PUBLIC nucleus)

find_package(Catch2 CONFIG REQUIRED)

set(TESTS_FILES
    tests/Main.cpp
    tests/Mat4Tests.cpp
    tests/TransformTests.cpp
    tests/Vec2Tests.cpp
    tests/Vec3Tests.cpp
    tests/Vec4Tests.cpp
    )

nucleus_add_executable(floatsTests ${TESTS_FILES})
target_link_libraries(floatsTests PRIVATE floats)
target_link_libraries(floatsTests PRIVATE Catch2::Catch2)
