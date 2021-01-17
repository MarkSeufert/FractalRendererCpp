#pragma once

#include <iostream>
#include "ColoringSchemes/Blue.h"
#include "Fractals/Mandelbrot.h"
#include "Renderer/Renderer.h"
#include <chrono>

using namespace std;

int main()
{
	// Set the window's width and height if they are passed as command line arguments
	int windowWidth = 1280;
	int windowHeight = 720;
	// TODO: Add argc and argv command line arg functionality

	// Create a fractal renderer window with a passed width and height
	Renderer renderer(windowWidth, windowHeight, "Mandelbrot Viewer");

	// Set the render's fractal to the mandelbrot set
	renderer.SetFractal(new Mandelbrot());

	// Set the coloring scheme to blue
	renderer.SetColorScheme(new Blue()); 

	// Continuously render the fractal
	auto timeInterval = chrono::steady_clock::now();
	while (renderer.Draw()) {
		cout << "Time(s): " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - timeInterval).count() / (1000.0) << endl;
		timeInterval = chrono::steady_clock::now();
	}

	return 0;
}
