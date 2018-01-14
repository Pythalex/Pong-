#include "game.hpp"

#include "board.hpp"
#include "Piece.hpp"
#include "Ball.hpp"
#include <random>
#include <ctime>
#include "math.hpp"

#include <iostream>

const int STICK_WIDTH = 20;
const int STICK_HEIGHT = 100;
const int BALL_WIDTH = 20;
const int BALL_HEIGHT = 20;

Piece player1;
Piece player2;
Ball ball;

float playerSpeed = 15;

void initGame() {
	player1 = Piece(5, BOARD_HEIGHT / 2 - STICK_HEIGHT / 2, STICK_WIDTH, STICK_HEIGHT);
	player2 = Piece(BOARD_WIDTH - 5 - STICK_WIDTH, BOARD_HEIGHT / 2 - STICK_HEIGHT / 2, STICK_WIDTH, STICK_HEIGHT);
	ball = Ball(BOARD_WIDTH / 2 - BALL_WIDTH / 2, BOARD_HEIGHT / 2 - BALL_HEIGHT / 2,
		BALL_WIDTH, BALL_HEIGHT);

	srand(time(NULL));

	ball.angleX = rand() % 100 < 50 ? 1 : -1;
	ball.angleY = 0;
	normalize(&ball.angleX, &ball.angleY);

	ball.speed = 12;
}

void reset() {

	player1.y = BOARD_HEIGHT / 2 - STICK_HEIGHT / 2;
	player2.y = BOARD_HEIGHT / 2 - STICK_HEIGHT / 2;

	ball.x = BOARD_WIDTH / 2 - BALL_WIDTH / 2;
	ball.y = BOARD_HEIGHT / 2 - BALL_HEIGHT / 2;

	ball.angleX = rand() % 100 < 50 ? 1 : -1;
	ball.angleY = 0;
	normalize(&ball.angleX, &ball.angleY);

	ball.speed = 12;
}

void update(GLFWwindow* win) {
	
	/// INPUTS

	//player 1
	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS) {
		player1.move(0, -10, nullptr);
	}
	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS) {
		player1.move(0, 10, nullptr);
	}

	// player 2
	if (rand() % 100 < 80) {
		
		if (!(ball.angleX == 1 && ball.y > player2.y && ball.y < player2.y + player2.h)) {
			if (ball.y <= player2.y && ball.angleY < 0)
				player2.move(0, -playerSpeed, nullptr);
			else if (ball.y >= player2.y && ball.angleY > 0)
				player2.move(0, playerSpeed, nullptr);
		} // else don't move
	}

	/// BALL

	unsigned int spot = -1;

	// collision with player 1?
	if (collision(ball.x + ball.angleX * ball.speed, ball.y + ball.angleY * ball.speed, ball.w, ball.h,
		player1.x, player1.y, player1.w, player1.h, &spot)) {
		ball.bounce(spot);
		ball.speed += 0.5;
	}
	// collision with player 2 ?
	else if (collision(ball.x + ball.angleX * ball.speed, ball.y + ball.angleY * ball.speed, ball.w, ball.h,
		player2.x, player2.y, player2.w, player2.h, &spot)) {
		ball.bounce(spot);
		ball.speed += 0.5;
	}
	// leave the board ? else move
	else if (!ball.move(ball.speed * ball.angleX, ball.speed * ball.angleY, &spot)) {
		if (spot != TOP && spot != BOTTOM)
			reset();
		else
			ball.bounce(spot);
	} 
}

void draw(GLFWwindow* win) {
	drawRect(win, player1.x, player1.y, player1.w, player1.h);
	drawRect(win, player2.x, player2.y, player2.w, player2.h);
	drawRect(win, ball.x, ball.y, ball.w, ball.h);
}