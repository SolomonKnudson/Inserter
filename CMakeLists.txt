cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

#Stop module flags from being passed
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

project(Operator LANGUAGES CXX)

add_library(Operator INTERFACE)

target_include_directories(Operator INTERFACE 
  "${CMAKE_CURRENT_LIST_DIR}/include/"
)

target_compile_features(Operator INTERFACE
  cxx_std_17
)

include(FetchContent)
FetchContent_Declare(
  TypeTraitsWrapper
  GIT_REPOSITORY https://github.com/SolomonKnudson/TypeTraitsWrapper.git   
  GIT_TAG main
)
FetchContent_MakeAvailable(TypeTraitsWrapper)
target_link_libraries(Operator INTERFACE TypeTraitsWrapper) 

#For internal development only
if(PROJECT_IS_TOP_LEVEL)
add_library(debug_warnings INTERFACE)
target_compile_options(debug_warnings INTERFACE
  $<$<AND:$<CONFIG:Debug>,$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>>:
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wconversion
    -Wmissing-declarations
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wformat=2
    -Wnull-dereference
    -Woverloaded-virtual
    -Wsign-conversion
    -Wundef
    -Wdouble-promotion
    -Wcast-align
    -Wcast-qual
    # -Werror
   >
)

add_library(debug_build_flags INTERFACE)
target_compile_options(debug_build_flags INTERFACE
  $<$<AND:$<CONFIG:Debug>,$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>>:
    -O0
    -g3
   >
)

target_link_libraries(Operator INTERFACE
  debug_warnings
  debug_build_flags
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/app)
endif()
