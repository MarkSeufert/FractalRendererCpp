cmake_minimum_required (VERSION 3.8)

project ("MandelbrotViewer")

# Include sub-projects.
add_subdirectory ("glfw")
add_subdirectory ("MandelbrotViewer")

target_include_directories (MandelbrotViewer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
