#pragma once

#include <iostream>
#include "ColoringSchemes/Classic.h"
#include "Fractals/Mandelbrot.h"
#include "Renderer/Renderer.h"
#include <chrono>

using namespace std;

int main()
{
	// User instructions
	cout << "This example renders the Mandelbrot Set." << endl;
	cout << "Commands:" << endl;
	cout << "\t- 'Left Click + Mouse' to pan" << endl;
	cout << "\t- 'Mouse Scroll Wheel' to zoom" << endl;
	cout << "\t- 'r' to reset back to the Mandelbrot Set" << endl;
	cout << "\t- 'q' and 'w' to increase/decrease the amount of iterations" << endl;
	
	// Set the window's width and height if they are passed as command line arguments
	int windowWidth = 1280;
	int windowHeight = 720;
	// TODO: Add argc and argv command line arg functionality

	// Create a fractal renderer window with a passed width and height
	Renderer renderer(windowWidth, windowHeight, "Mandelbrot Viewer");

	// Set the render's fractal to the mandelbrot set
	renderer.SetFractal(new Mandelbrot);

	// Set the coloring scheme to blue
	renderer.SetColorScheme(new Classic());

	// Continuously render the fractal
	while (renderer.Draw()) { }

	return 0;
}
