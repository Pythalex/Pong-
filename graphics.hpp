#ifndef GRAPHICS_HPP_INCLUDED
#define GRAPHICS_HPP_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

/**
 * Initializes graphic functions
 */
void initGraphics();

void terminateGraphics();

/**
 *	Draw every VAOs
 */
void drawEverything(GLFWwindow* win);

void destroyObjects();

bool indexOf(std::vector<unsigned int> arr, unsigned int elm, int *index);

/**
 * Draws a rectangle 
 * @param x coord
 * @param y coord
 * @param width in px
 * @param height in px
 */
void drawRect(GLFWwindow* win, float x, float y, float width, float height);

/**
* Draws a triangle
* @param x1 coord
* @param y1 coord
* @param x2 coord
* @param y2 coord
* @param x3 coord
* @param y3 coord
*/
void drawTriangle(GLFWwindow* win, float x1, float y1, float x2, float y2, float x3, float y3);

#endif