#include "ColoringInterface.h"

/*
This class defines a coloring scheme that renders the fractal in a blueish color with a black core.
*/
class ColoringBlue : public ColoringInterface
{
	void GetColor(double iterationRatio, double& r, double& g, double& b) override
	{
		// Square the iterationRatio to skew it towards 0, which emphasizes the coloring near 0
		iterationRatio = iterationRatio * iterationRatio;

		r = 1 - iterationRatio * 0.85;
		g = 1 - iterationRatio * 0.8;
		b = 1 - iterationRatio * iterationRatio / 2;
	}
};