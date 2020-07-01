#======================================================================
# Juniper/dependencies
#======================================================================
add_subdirectory(glfw)
#set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
SET_TARGET_PROPERTIES(glfw PROPERTIES FOLDER "{$PROJECT_NAME}/Dependencies")

add_subdirectory(spdlog)