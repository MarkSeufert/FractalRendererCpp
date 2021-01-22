#include "Renderer/ColoringInterface.h"

/*
This class defines a coloring scheme that renders the fractal in black and white.
*/
class Greyscale : public ColoringInterface
{
	void GetColor(double iterationRatio, double& r, double& g, double& b) override
	{
		if (iterationRatio >= 0.99)
		{
			r = 0;
			g = 0;
			b = 0;
			return;
		}

		iterationRatio = 1 - iterationRatio;

		// Square the iterationRatio to skew it towards 0, which emphasizes the coloring near 0
		iterationRatio = iterationRatio * iterationRatio;

		r = 1 - iterationRatio * 0.9;
		g = 1 - iterationRatio * 0.9;
		b = 1 - iterationRatio * 0.9;
	}
};