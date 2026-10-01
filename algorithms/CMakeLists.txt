set(ALGORITHM_SOURCES 
  n-queens.cpp
)

add_library(SimpleAlgorithms STATIC ${ALGORITHM_SOURCES})
add_library(Simple::Algorithms ALIAS SimpleAlgorithms)

target_include_directories(SimpleAlgorithms
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(SimpleAlgorithms PUBLIC cxx_std_20)
target_link_libraries(SimpleAlgorithms PUBLIC Simple::Common)