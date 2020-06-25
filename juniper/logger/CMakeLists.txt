#======================================================================
# Juniper/juniper/logger
#======================================================================

add_library(
  J_Logger
  Logger.h
  Logger.cpp)

target_link_libraries(
  J_Logger
  INTERFACE
  SpdLog)

set_target_properties(
  J_Logger
  PROPERTIES
  FOLDER {PROJECT_NAME}/libs)