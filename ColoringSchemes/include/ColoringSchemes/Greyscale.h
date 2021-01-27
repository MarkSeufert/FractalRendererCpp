#include "Renderer/ColoringInterface.h"

/*
This class adds a very basic coloring scheme with two color points (black and white).
*/
class Greyscale : public ColoringInterface
{
public:
	/*
	The constructor automatically adds color points to the ColoringInterface
	*/
	Greyscale()
	{
		SetColorPoint(0, 1, 1, 1);
		SetColorPoint(1, 0, 0, 0);
	}
};