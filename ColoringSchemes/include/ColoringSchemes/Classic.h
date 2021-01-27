#include "Renderer/ColoringInterface.h"

/*
This class adds a coloring scheme similar to the one found on the Mandelbrot wikipedia page, found from this post:
https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia
*/
class Classic : public ColoringInterface
{
public:
	/*
	The constructor automatically adds color points to the ColoringInterface
	*/
	Classic()
	{
		SetColorPoint(0   ,   0 / 255.0,   7 / 255.0, 100 / 255.0);
		SetColorPoint(0.16,  32 / 255.0, 107 / 255.0, 203 / 255.0);
		SetColorPoint(0.42, 237 / 255.0, 255 / 255.0, 255 / 255.0);
		SetColorPoint(0.65, 255 / 255.0, 170 / 255.0,   0 / 255.0);
		SetColorPoint(0.86, 150 / 255.0,  32 / 255.0,   0 / 255.0);
		SetColorPoint(1   ,   0 / 255.0,   0 / 255.0,   0 / 255.0);
	}
};