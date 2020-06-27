#======================================================================
# Juniper
#======================================================================

cmake_minimum_required(VERSION 3.14)

project(Juniper VERSION 0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#======================================================================
# Include Juniper dependencies directories and libraries
#======================================================================
include_directories(
  ${PROJECT_SOURCE_DIR}/juniper/dependencies)

#======================================================================
# Include Juniper directories and libraries
#======================================================================
include_directories(
  ${PROJECT_SOURCE_DIR}/juniper/src
  ${PROJECT_SOURCE_DIR}/juniper/src/logger
  ${PROJECT_SOURCE_DIR}/juniper/src/world)

list(APPEND J_LIBS J_App)
list(APPEND J_LIBS J_Logger)
list(APPEND J_LIBS J_World)

#======================================================================
# Subdirectories
#======================================================================
add_subdirectory(app)
add_subdirectory(juniper)

#======================================================================
# Entry Point
#======================================================================
add_executable(JuniperApp Entry.cpp)

target_link_libraries(
  JuniperApp
  PRIVATE
  ${J_LIBS})
