#include "Renderer/ColoringInterface.h"

/*
This class adds a coloring scheme similar to the one found on the Mandelbrot wikipedia page, found from this post:
https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia
*/
class Rainbow : public ColoringInterface
{
public:
	/*
	The constructor automatically adds color points to the ColoringInterface
	*/
	Rainbow()
	{
		SetColorPoint(0, 0, 0, 1);
		SetColorPoint(0.08, 0, 1, 1);
		SetColorPoint(0.15, 0, 1, 0);
		SetColorPoint(0.22, 1, 1, 0);
		SetColorPoint(0.3, 1, 0, 0);
		SetColorPoint(0.55, 1, 0, 1);
		SetColorPoint(0.9, 1, 1, 1);
		SetColorPoint(1, 0, 0, 0);

	}
};