#include "MandelbrotViewer.h"

using namespace std;

int main()
{
	if (!glfwInit()) {
		cout << "GLFW was not initialized properly" << endl;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1600, 900, "Mandelbrot Viewer", nullptr, nullptr);
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
