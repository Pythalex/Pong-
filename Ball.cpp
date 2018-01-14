#include "Ball.hpp"
#include "board.hpp"

#include <iostream>
#include "math.hpp"

Ball::Ball() : Piece() {
	angleX = 1;
	angleY = 0;

	speed = 5;
}

Ball::Ball(float x, float y, float w, float h) : Piece(x, y, w, h) {
	angleX = 1;
	angleY = 0;

	speed = 5;
}

Ball::Ball(float x, float y, float w, float h, float angleX, float angleY) : Piece(x, y, w, h) {

	normalize(&angleX, &angleY);
	this->angleX = angleX;
	this->angleY = angleY;

	speed = 5;
}

Ball::Ball(float x, float y, float w, float h, float angleX, float angleY, float speed) : Piece(x, y, w, h) {

	normalize(&angleX, &angleY);
	this->angleX = angleX;
	this->angleY = angleY;

	this->speed = speed;
}

void Ball::bounce(unsigned int side) {
	if (side < 0 && side > 3) {
		std::cerr << "ERROR:BALL:BOUNCE : Given collision side were invalid (" << side << ").\n";
	}
	else {
		switch (side) {
			case 0: // right
			case 4: // left
				symmetryHorizontal(&angleX, &angleY);
				break;
			case 2: // up
			case 6: // down
				symmetryVertical(&angleX, &angleY);
				break;
			case 1: // top right
				angleX = -1;
				angleY = 1;
				normalize(&angleX, &angleY);
				break;
			case 3: // top left
				angleX = 1;
				angleY = 1;
				normalize(&angleX, &angleY);
				break;
			case 5: // bottom left
				angleX = 1;
				angleY = -1;
				normalize(&angleX, &angleY);
				break;
			case 7: // bottom right
				angleX = 1;
				angleY = 1;
				normalize(&angleX, &angleY);
			default:
				break;
		}
	}
}