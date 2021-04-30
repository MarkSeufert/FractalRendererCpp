#pragma once

#include <vector>

/*
This class defines a coloring scheme that renders the fractal linearly between user-defined colors. 
Several derived classes exist in the ./ColoringSchemes folder that already contain the inputed colors.
*/

class ColoringInterface
{
public:
	/*
	Given the iterationRatio, returns the RGB values by reference used to color this point. The iterationRatio
	is a value between 0 and 1, where a value closer to 1 means it is closer to being inside the fractal (1 is inside).
	*/
	void GetColor(double iterationRatio, double& r, double& g, double& b)
	{
		// Ensure there is atleast two colors to render
		if (mandelbrotValues_.size() < 2)
		{
			return;
		}

		// Find the two positions that the iterationRatio lies between
		int p = 0;
		for (p; p < mandelbrotValues_.size() - 1; p++)
		{
			if (iterationRatio <= mandelbrotValues_[p + 1])
				break;
		}

		// Linearly interpolate between mandelbrotValues_[p] and mandelbrotValues_[p + 1]
		double blendAmount = (iterationRatio - mandelbrotValues_[p]) / (mandelbrotValues_[p + 1] - mandelbrotValues_[p]);
		r = (red_[p + 1] - red_[p]) * blendAmount + red_[p];
		g = (green_[p + 1] - green_[p]) * blendAmount + green_[p];
		b = (blue_[p + 1] - blue_[p]) * blendAmount + blue_[p];
	}

	/*
	Adds a color point to the fractal. The mandelbrotValue is a value between 0 and 1, and the rgb values
	are the values to color that point. 
	*/
	void SetColorPoint(double mandelbrotValue, double r, double g, double b) 
	{
		// Add the RGB to their corresponding vectors
		red_.push_back(r);
		green_.push_back(g);
		blue_.push_back(b);

		// Add the mandelbrot value that renders this color
		mandelbrotValues_.push_back(mandelbrotValue);
	}

private:
	// Variables to store specific RGB points
	std::vector<double> red_;
	std::vector<double> green_;
	std::vector<double> blue_;
	std::vector<double> mandelbrotValues_;
};