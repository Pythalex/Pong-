#include "window.hpp"

bool FULLSCREEN = false;

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

GLFWwindow* createWindow() {
	return createWindow(WIDTH, HEIGHT);
}

GLFWwindow* createWindow(int width, int height) {
	GLFWwindow* window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);

	if (window == nullptr) {
		return nullptr;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "ERROR:GLAD:LOAD:LOAD_GL_FAILED\n";
		return nullptr;
	}

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	return window;
}

void toggleFullscreen(GLFWwindow* window) {
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vidmod = glfwGetVideoMode(monitor);

	glfwDestroyWindow(window);
	window = glfwCreateWindow(vidmod->width, vidmod->height, "Window",
		FULLSCREEN ? nullptr : monitor, nullptr);
	FULLSCREEN = !FULLSCREEN;
}

