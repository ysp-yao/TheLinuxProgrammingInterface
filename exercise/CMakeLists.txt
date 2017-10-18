cmake_minimum_required(VERSION 3.6)



INCLUDE_DIRECTORIES(
  ./lib
)

add_subdirectory(lib)

add_executable(
  e3_1
  e3_1.c
)

add_executable(
  e4_1
  e4_1.c
)

add_executable(
  e4_2
  e4_2.c
)

target_link_libraries(e4_2 utils)

add_executable(
  e5_2
  e5_2.c
)

target_link_libraries(e5_2 utils)
add_executable(
  e5_3
  e5_3.c
)

target_link_libraries(e5_3 utils)
