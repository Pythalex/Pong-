#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// DEFAULT CONFIG
extern bool FULLSCREEN; // default video mode
const int WIDTH = 640; // default window width
const int HEIGHT = 480; // default window height

/**
* User resize management
*/
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

/**
* Creates and returns a glfw window, makes the window
* the current context, initializes glad, viewport and framebuffersize callback.
* GLFW must have been initialized.
*/
GLFWwindow* createWindow();

/**
* Creates and returns a glfw window, makes the window
* the current context, initializes glad, viewport and framebuffersize callback.
* GLFW must have been initialized.
*
* @param width : width in px
* @param height : height in px
*/
GLFWwindow* createWindow(int width, int height);


/**
* Toggle fullscreen for given window
*/
void toggleFullscreen(GLFWwindow* window);

#endif