#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics.hpp"

void initGame();

void update(GLFWwindow* win);

void draw(GLFWwindow* win);

#endif