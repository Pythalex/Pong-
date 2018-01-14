#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"
#include "graphics.hpp"

#include "game.hpp"

void initializeGLFW(int major, int minor) {
	// init glfw and glad 
	glfwInit();

	// indicate glfw version + opengl profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int main() {

	initializeGLFW(3, 3);
	GLFWwindow* win = createWindow(640, 480);
	initGraphics();

	if (win == NULL) {
		return -1;
	}

	initGame();

	while (!glfwWindowShouldClose(win)) {

		drawEverything(win);

		glfwPollEvents();
		update(win);
		draw(win);
	}

	glfwDestroyWindow(win);
	glfwTerminate();
	terminateGraphics();

	return 0;
}