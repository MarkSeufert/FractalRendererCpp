#include "MandelbrotViewer.h"
#include "ColoringBlue.h"

using namespace std;

int main()
{
	if (!glfwInit()) {
		cout << "GLFW was not initialized properly" << endl;
		return -1;
	}

	// Delete this later, testing color interface
	ColoringInterface* coloringScheme = new ColoringBlue;
	double r, g, b;
	coloringScheme->GetColor(0.9, r, g, b);
	cout << "Returned color: (" << r << ", " << g << ", " << b << ") " << endl;
	delete coloringScheme;

	GLFWwindow* window = glfwCreateWindow(160, 90, "Mandelbrot Viewer", nullptr, nullptr);
	if (!window)
	{
		cout << "Window was not created properly" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (true) {}
	return 0;
}
