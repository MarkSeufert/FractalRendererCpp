cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (MandelbrotViewer "MandelbrotViewer.cpp" "MandelbrotViewer.h")

# TODO: Add tests and install targets if needed.
target_link_libraries (MandelbrotViewer glfw)
