#pragma once

#include <iostream>
#include "ColoringSchemes/Rainbow.h"
#include "Fractals/Mandelbrot.h"
#include "Fractals/Julia.h"
#include "Renderer/Renderer.h"
#include <chrono>

using namespace std;

int main()
{
	// User instructions
	cout << "This example renders any Julia Set given a corresponding point from the Mandelbrot Set." << endl;
	cout << "Commands:" << endl;
	cout << "\t- 'Left Click + Mouse' to pan" << endl;
	cout << "\t- 'Mouse Scroll Wheel' to zoom" << endl;
	cout << "\t- 'Right Click + Mouse' to draw the Julia Set of the point at the mouse's position" << endl;
	cout << "\t- 'r' to reset back to the Mandelbrot Set" << endl;
	cout << "\t- 'q' and 'w' to increase/decrease the amount of iterations" << endl;
	cout << "\n\n";

	// Set the window's width and height if they are passed as command line arguments
	int windowWidth = 1280;
	int windowHeight = 720;
	// TODO: Add argc and argv command line arg functionality

	// Create a fractal renderer window with a passed width and height
	Renderer renderer(windowWidth, windowHeight, "Julia Viewer");

	// Set the render's fractal to the mandelbrot set
	Mandelbrot* mandelbrot = new Mandelbrot();
	renderer.SetFractal(mandelbrot);

	// Set the coloring scheme to blue
	renderer.SetColorScheme(new Rainbow());

	// Get a pointer to the User Inputs variable from the Renderer
	Inputs* inputs = renderer.GetInputs();

	// Continuously render the fractal
	double x = 0;
	while (renderer.Draw()) {
		// Check if the user clicked the right mouse button
		if (inputs->rightClick)
		{
			// Generate a Julia Set at this point, and assign it to the fractal
			cout << "Generating Julia Set at point ( " << inputs->mouseX << ", " << inputs->mouseY << " ) \r";
			renderer.SetFractal(new Julia(inputs->mouseX, inputs->mouseY));
		}

		// If the user pressed 'R', reset the fractal to the mandelbrot set
		if (inputs->latestChar == 'R') 
		{
			renderer.SetFractal(mandelbrot);
		}
	}

	return 0;
}
