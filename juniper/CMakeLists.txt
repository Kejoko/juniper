#======================================================================
# Juniper/juniper
#======================================================================
add_subdirectory(logger)
add_subdirectory(world)

add_library(
  J_App
  App.h
  App.cpp)

set_target_properties(
  J_App
  PROPERTIES
  FOLER {PROJECT_NAME}/libs)