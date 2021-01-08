#pragma once

#include <iostream>
#include "GLFW/glfw3.h"
#include "ColoringSchemes/Blue.h"
#include "Fractals/Mandelbrot.h"
#include "Renderer/Renderer.h"

using namespace std;

int main()
{
	// Set the window's width and height if they are passed as command line arguments
	int windowWidth = 1200;
	int windowHeight = 800;
	// TODO: Add argc and argv command line arg functionality

	// Create a fractal renderer window with a passed width and height
	Renderer renderer(windowWidth, windowHeight, "Mandelbrot Viewer");

	// Set the render's fractal to the mandelbrot set
	renderer.SetFractal(new Mandelbrot());

	// Set the coloring scheme to blue
	renderer.SetColorScheme(new Blue());

	// Continuously render the fractal
	while (true)
	{
		renderer.Draw();
	}

	return 0;
}
