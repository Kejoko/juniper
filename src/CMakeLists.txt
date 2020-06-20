#======================================================================
# Juniper/juniper
#======================================================================
add_subdirectory(logger)

add_library(
  J_App
  ${PROJECT_SOURCE_DIR}/include/App.h
  App.cpp)