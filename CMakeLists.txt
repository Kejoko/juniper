#======================================================================
# Juniper
#======================================================================

cmake_minimum_required(VERSION 3.17)

project(Juniper VERSION 0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

List(APPEND CMAKE_MODULE_PATH
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#======================================================================
# Preprocessor directives
#======================================================================
option(DEBUG_MODE "Debug mode" ON)
if(DEBUG_MODE)
  add_compile_definitions(DEBUG)
else()
  add_compile_definitions(RELEASE)
endif(DEBUG_MODE)
unset(DEBUG_MODE CACHE)

#======================================================================
# C++ 11 Support
#======================================================================
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=gnu++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=gnu++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
endif()

#======================================================================
# Subdirectories
#======================================================================
add_subdirectory(app)
add_subdirectory(juniper)

#======================================================================
# Packages and libraries
#======================================================================
set(J_LIBS)

#======================================================================
# Entry Point
#======================================================================
add_executable(JuniperApp Entry.cpp)

target_link_libraries(JuniperApp PRIVATE
  J_Logger)
