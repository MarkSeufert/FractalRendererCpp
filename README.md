# Fractal Rendering Library for C++
![A Rendering of the Mandelbrot set](https://drive.google.com/uc?id=1D9b8U0TuQO6sJ1WqAlbObbn7DW_RRRhE)

FractalRendererCpp is an open-source fractal rendering library built in C++. It allows users to render popular fractals (such as the Mandelbrot set), and navigate through them at runtime using their mouse and keyboard.

**Table Of Contents**
  * [Features](#features)
  * [Project Structure](#project-structure)
  * [Downloading the Project](#downloading-the-project)
  * [Building the Project](#building-the-project)
  * [Examples](#examples)

## Features
  - **Graphical.** It is amazing to visualize the beauty of mathematics. The Rendering Library uses OpenGL, and [GLFW](https://github.com/glfw/glfw) and [GLEW](https://github.com/Perlmint/glew-cmake) as helper libraries, to create a graphical application that renders a fractal in vivid colors.
  - **Interactive.** The library is fully interactive, allowing users to zoom and pan across the fractals using the mouse. Keyboard inputs are also supported, used for modifying the number of iterations and resetting the rendering.
  - **Customizable.** The Rendering Library allows for customization in several aspects:
    1. A user can implement their own fractals by extending from the [Fractal Interface](https://github.com/MarkSeufert/FractalRendererCpp/blob/master/Renderer/include/Renderer/FractalInterface.h), and passing it to the renderer. Several popular fractals have already been implemented, located inside [this folder](https://github.com/MarkSeufert/FractalRendererCpp/tree/master/Fractals/include/Fractals).
    2. A user can create a custom coloring scheme for the fractals by extending from the [Coloring Interface](https://github.com/MarkSeufert/FractalRendererCpp/blob/master/Renderer/include/Renderer/ColoringInterface.h). Several default coloring schemes have already been created, located inside [this folder](https://github.com/MarkSeufert/FractalRendererCpp/tree/master/ColoringSchemes/include/ColoringSchemes).
    3. Custom Input logic can be implemented using the information from the UserInputs class, which can be seen in the JuliaRenderer example (link). 
  - **Multithreaded.** Fractal computations are very intensive, so this project makes use of all your computer's cores to make it as fast as possible.
  - **Cross platform.** This project uses [CMake](https://cmake.org/) such that it can be built on Windows, Mac, and Linux.
  
## Running the Project
### **Step 1**: Cloning the Project
The first step to building this project is to clone it locally onto your computer. This is done by executing the command `git clone https://github.com/MarkSeufert/FractalRendererCpp.git`.
After the project is cloned, there are two git Submodules that need to be initialized (GLEW and GLFW). This is done by navigating into the repository's folder through the command line, and typing `git submodule init` followed by `git submodule update`. The project is now successfully downloaded.
  
### **Step 2**: Building the Project
This project uses CMake as a build tool. If you haven't already done so, [download and install CMake](https://cmake.org/download/). To generate a C++ project, navigate into the repository folder and  type `CMake .`. This will generate a C++ project you can open in the current directory.

### **Step 3**: Running the Examples
After running the CMake commands from above, there should now a C++ project file that you can open (ex: a Visual Studio `.sln` file). After opening it, there should be six folders in the project tree (see [Project Structure](#project-structure) for more details). The examples are located in the examples/ folder, so set that project as the startup project. Open one of the cpp files in this folder, and 
compile it. If all is good, there will be no compilation errors and there will be a window rendering a fractal!

## Examples
This project will contain two examples: a Mandelbrot set renderer and a Julia Set renderer. (Insert pictures).

## Project Structure
The project contains 6 folders total, 4 of which are specific to this project and the other 2 being git submodules. The structure and description is shown below:

```
FractalRendererCpp
│   README.md
│   CMakeLists.txt    
│
└───Renderer: Contains the fractal rendering library 
│   │   CMakeLists.txt
│   │
│   └───include/Renderer
│       │   ColoringInterace.h
│       │   FractalInterface.h
│       │   Renderer.h 
│       │   UserInputs.h
│   ────src
│       │   Renderer.cpp
│   
└───Fractals/include/Fractals: Contains implementations of popular fractals, such as the Mandelbrot set
│   │   Mandelbrot.h
│   │   Julia.h
│   │   BurningShip.h
│   
└───ColoringSchemes/include/ColoringSchemes: Contains implementations of coloring schemes to render the fractals
│   │   Mandelbrot.h
│   │   Julia.h
│   │   BurningShip.h
│
└───Examples: Contains compilable examples
│   │   CMakeLists.txt
│   │   MandelbrotRenderer.h
│   │   JuliaRenderer.h
│
└───(Git Submodule) GLFW: Contains the GLFW helper library for OpenGL
│
└───(Git Submodule) GLEW: Contains the GLEW helper library for OpenGL
```
