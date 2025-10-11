set(DATASTRUCTURES_SOURCES
  linked-list.cpp
)

add_library(SimpleDataStructures STATIC ${DATASTRUCTURES_SOURCES})
add_library(Simple::DataStructures ALIAS SimpleDataStructures)

target_include_directories(SimpleDataStructures
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(SimpleDataStructures PUBLIC cxx_std_20)
target_link_libraries(SimpleDataStructures PUBLIC Simple::Common)