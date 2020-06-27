#======================================================================
# Juniper/juniper/world
#======================================================================

add_library(
  J_World
  Chunk.h
  Level.h
  World.h
  Chunk.cpp
  Level.cpp
  World.cpp)

set_target_properties(
  J_World
  PROPERTIES
  FOLER {PROJECT_NAME}/libs)