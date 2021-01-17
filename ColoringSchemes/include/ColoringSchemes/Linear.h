#include "Renderer/ColoringInterface.h"

/*
This class defines a coloring scheme that renders the fractal linearly between values, found from this post:
https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia
*/
class Linear : public ColoringInterface
{
public:
	const double positions[6] = {       0,      0.16,      0.42,    0.6425,    0.8575,       1 };
	const double red[6]       = {   0 / 255.0,  32 / 255.0, 237 / 255.0, 255.0 / 255.0, 0 / 255.0, 0 };
	const double green[6]     = {   7 / 255.0, 107 / 255.0, 255.0 / 255.0, 170 / 255.0, 2 / 255.0, 0 };
	const double blue[6]      = { 100 / 255.0, 203 / 255.0, 255.0 / 255.0,   0 / 255.0, 0 / 255.0, 0 };
	void GetColor(double iterationRatio, double& r, double& g, double& b) override
	{
		// Find the two positions that the iterationRatio lies between
		int p = 0;
		for (p; p < 5; p++)
		{
			if (iterationRatio <= positions[p + 1])
				break;
		}

		// Linearly interpolate between positions[p] and positions[p+1]
		double blendAmount = (iterationRatio - positions[p]) / (positions[p + 1] - positions[p]);
		r = (red[p + 1]   -   red[p]) * blendAmount +   red[p];
		g = (green[p + 1] - green[p]) * blendAmount + green[p];
		b = (blue[p + 1]  -  blue[p]) * blendAmount +  blue[p];
	}
};