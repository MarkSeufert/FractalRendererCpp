# Fractal Rendering Library for C++
![A Rendering of the Mandelbrot set](https://drive.google.com/uc?id=1D9b8U0TuQO6sJ1WqAlbObbn7DW_RRRhE)

FractalRendererCpp is an open-source fractal rendering engine built in C++. The fractals are calculated at runtime, and can be interacted with using the mouse and keyboard.

**Table Of Contents**
  * [Features](#features)
  * [Project Structure](#project-structure)
  * [Downloading the Project](#downloading-the-project)
  * [Building the Project](#building-the-project)
  * [Examples](#examples)

## Features
  - **Cross platform.** This project uses [CMake](https://cmake.org/) such that it can be built on Windows, Mac, and Linux.
  - **Graphical.** It is amazing when the beautify of mathematics can be seen. The Rendering Library uses OpenGL, and GLFW and GLEW as helper libraries, to create a graphical application that renders a fractal in vivid colors.
  - **Interactive.** The library is fully interactive, allowing users to zoom and pan across the fractals using the mouse. Keyboard inputs are also supported, used for modifying the number of iterations and resetting the rendering.
  - **Customizable.** The Rendering Library allows for customization in several aspects:
    1. A user can implement their own fractals by extending from the [Fractal Interface](https://github.com/MarkSeufert/FractalRendererCpp/blob/master/Renderer/include/Renderer/FractalInterface.h), and passing it to the renderer. Several default fractals have already been implemented, located inside [this folder](https://github.com/MarkSeufert/FractalRendererCpp/tree/master/Fractals/include/Fractals).
    2. A user can create a custom coloring scheme for the fractals by extending from the [Coloring Interface](https://github.com/MarkSeufert/FractalRendererCpp/blob/master/Renderer/include/Renderer/ColoringInterface.h). Several default coloring schemes have already been created, located inside [this folder](https://github.com/MarkSeufert/FractalRendererCpp/tree/master/ColoringSchemes/include/ColoringSchemes).
    3. Custom Input logic can be implemented using the information from the UserInputs class, which can be seen in the JuliaRenderer example (link). 
  - **Multithreaded.** Fractal computations are very intensive, so this project makes use of all your computer's cores to make it as fast as possible.
  
## Project Structure
Show the heirarchy of folders and what each folder contains
  
## Downloading the Project
The first step to building this project is to clone it locally onto your computer. This is done by executing git clone "some http link".
After the project is cloned, there are two Git Submodules that need to be initialized (GLEW and GLFW). This is done by navigating into the repository's folder through the command line, and typing 'git submodule init' followed by 'git submodule update'. 
  
## Building the Project
This project uses CMake as a build tool. If you haven't already done so, download and install cmake from (link). To generate a C++ project, navigate into the repository folder and  type "CMake .". This will generate a project in the current directory

## Examples
There are several examples included under the Examples/ directory. Each of the examples renders a different fractal with a different coloring scheme used. 
