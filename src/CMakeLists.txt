cmake_minimum_required(VERSION 3.20)
project(MathLibExample)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/math_lib/include)

add_executable(MathLibExample main.cpp)

add_subdirectory(math_lib)

target_link_libraries(MathLibExample math_library)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.15.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(MathLibTests test/main.cpp) 
target_link_libraries(MathLibTests gtest_main math_library)

enable_testing()
add_test(NAME MathLibTests COMMAND MathLibTests)
