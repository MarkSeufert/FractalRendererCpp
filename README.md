# Fractal Renderer for C++
An interactive fractal viewer built in C++.
![alt text](https://drive.google.com/uc?id=12cN-74PhcpFSjAJJaOJD-igUkjRrYmeP)](https://github.com/nlohmann/json/releases)

## Features:
  - Cross platform. Uses CMake such that it can be built on Windows, Mac, and Linux.
  - Interactive. The user can select segments of the Mandelbrot set to zoom into.
  - Uses OpenGL with the help of GLEW and GLFW
  - Fully Extensable. The renderer can render any fractal that operates on (real, complex) numbers, so it is easy to add your own fractal.
  - Multithreaded. Fractal computations are very intensive, so this project makes use of all your computer's cores to make it as fast as possible.
  
## Project Structure
Show the heirarchy of folders and what each folder contains
  
## Downloading the Project
The first step to building this project is to clone it locally onto your computer. This is done by executing git clone "some http link".
After the project is cloned, there are two Git Submodules that need to be initialized (GLEW and GLFW). This is done by navigating into the repository's folder through the command line, and typing 'git submodule init' followed by 'git submodule update'. 
  
## Building the Project
This project uses CMake as a build tool. If you haven't already done so, download and install cmake from (link). To generate a C++ project, navigate into the repository folder and  type "CMake .". This will generate a project in the current directory

## Examples
There are several examples included under the Examples/ directory. Each of the examples renders a different fractal with a different coloring scheme used. 
