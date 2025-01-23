cmake_minimum_required(VERSION 3.27)
project(libcmathext)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/marve/vcpkg/scripts/buildsystems/vcpkg.cmake")

include(C:\\Users\\marve\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake)

include_directories(src/fibonacci)
include_directories(src/gauss)
include_directories(src/graph)
include_directories(src/graph/mfset)
include_directories(src/graph/node)
include_directories(src/libcmathext)
include_directories(src/mcd)
include_directories(src/mcm)
include_directories(src/polygon)
include_directories(src/prime)
include_directories(src/sum)

add_executable(libcmathext
        src/fibonacci/fibonacci.cpp
        src/fibonacci/fibonacci.h
        src/gauss/gauss.cpp
        src/gauss/gauss.h
        src/graph/mfset/mfset.cpp
        src/graph/mfset/mfset.h
        src/graph/node/node.cpp
        src/graph/node/node.h
        src/graph/graph.cpp
        src/graph/graph.h
        src/libcmathext/libcmathext.cpp
        src/libcmathext/libcmathext.h
        src/mcd/mcd.cpp
        src/mcd/mcd.h
        src/mcm/mcm.cpp
        src/mcm/mcm.h
        src/polygon/polygon.cpp
        src/polygon/polygon.h
        src/prime/prime.cpp
        src/prime/prime.h
        src/sum/sum.cpp
        src/sum/sum.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(main tests/test.cpp)
target_link_libraries(main gtest_main)
add_test(NAME example_test COMMAND example)
