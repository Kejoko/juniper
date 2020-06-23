#======================================================================
# Juniper/juniper/logger
#======================================================================

add_library(
  J_Logger
  Logger.h
  Logger.cpp)

set_target_properties(
  J_Logger
  PROPERTIES
  FOLER {PROJECT_NAME}/libs)