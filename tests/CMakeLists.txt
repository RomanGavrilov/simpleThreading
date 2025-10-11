# tests/CMakeLists.txt
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For MSVC: avoid CRT conflicts
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(simplethreading_tests
  test-linked-list.cpp
)

target_link_libraries(simplethreading_tests
  PRIVATE
    GTest::gtest_main
    Simple::DataStructures 
    Simple::Common
)

include(GoogleTest)
gtest_discover_tests(simplethreading_tests)
