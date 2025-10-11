add_executable(simplethreading
  main.cpp
)

target_link_libraries(simplethreading
  PRIVATE
    Simple::Common
    Simple::DataStructures
)
