#======================================================================
# Juniper
#======================================================================

cmake_minimum_required(VERSION 3.14)

project(Juniper VERSION 0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wfatal-errors")

#======================================================================
# Preprocessor directives
#======================================================================
option(DEBUG_MODE "Debug mode" ON)
option(RELEASE_MODE "Release mode" OFF)
if(DEBUG_MODE)
  add_compile_definitions(DEBUG)
else()
  option(RELEASE_MODE "Release mode" ON)
  add_compile_definitions(RELEASE)
endif(DEBUG_MODE)
unset(DEBUG_MODE CACHE)
unset(RELEASE_MODE CACHE)

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

if(APPLE)
  include_directories(${PROJECT_SOURCE_DIR}/juniper/dependencies/glfw/mac/include)
  link_directories(${PROJECT_SOURCE_DIR}/juniper/dependencies/glfw/mac/lib-macos)
  list(APPEND DEP_LIBS libglfw.3.dylib)
  list(APPEND DEP_LIBS "-framework OpenGL")
endif()

if(WIN32)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	include_directories(${PROJECT_SOURCE_DIR}/juniper/dependencies/glfw/windows64/include)
	link_directories(${PROJECT_SOURCE_DIR}/juniper/dependencies/glfw/windows64/lib-vc2019)
	list(APPEND DEP_LIBS glfw3.dll)
  else()
    include_directories(${PROJECT_SOURCE_DIR}/juniper/dependencies/glfw/windows32/include)
	link_directories(${PROJECT_SOURCE_DIR}/juniper/dependencies/glfw/windows32/lib-vc2019)
	list(APPEND DEP_LIBS glfw3.dll)
  endif()
endif()

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
  ${DEP_LIBS}
  ${J_LIBS})