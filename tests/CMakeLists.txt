include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.15.0.zip
)
FetchContent_MakeAvailable(googletest)

# Тестовий виконуваний файл
add_executable(MathLibUnitTests math_library_tests.cpp)
target_link_libraries(MathLibUnitTests
    PRIVATE
        gtest_main
        math_library
)
enable_testing()
add_test(NAME math_library_gtests COMMAND MathLibUnitTests)
