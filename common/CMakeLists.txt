# Header-only for now
add_library(SimpleCommon INTERFACE)
add_library(Simple::Common ALIAS SimpleCommon)

target_include_directories(SimpleCommon
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# --- When you add .cpp files to common/, switch to STATIC like this: ---
# add_library(SimpleCommon STATIC exceptions.cpp other.cpp)
# add_library(Simple::Common ALIAS SimpleCommon)
# target_include_directories(SimpleCommon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_compile_features(SimpleCommon PUBLIC cxx_std_20)
