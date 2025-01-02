cmake_minimum_required(VERSION 3.10)

project(G_2_array VERSION 1.0 LANGUAGES C)

set(SOURCES
  src/array.c
)

add_library(G_2_array_static STATIC ${SOURCES})
set_target_properties(G_2_array_static PROPERTIES
  OUTPUT_NAME "-2_array"
  POSITION_INDEPENDENT_CODE ON
)

add_library(G_2_array_shared SHARED ${SOURCES})
set_target_properties(G_2_array_shared PROPERTIES
  OUTPUT_NAME "-2_array"
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_include_directories(G_2_array_static
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external_include
)

target_include_directories(G_2_array_shared
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external_include
)

target_compile_definitions(G_2_array_static
  PRIVATE G_SHARED=0
)

target_compile_definitions(G_2_array_shared
  PRIVATE G_SHARED=1
)

install(TARGETS G_2_array_static G_2_array_shared
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  FILES
    include/-2_array.h
  DESTINATION
    include
)

install(
  FILES
    include/-2/array.h
    include/-2/array_types.h
    include/-2/array_macros.h
  DESTINATION
    include/-2
)
