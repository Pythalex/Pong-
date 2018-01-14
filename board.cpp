#include "board.hpp"

const int BOARD_WIDTH = 640;
const int BOARD_HEIGHT = 480;

// collision spots
const unsigned int RIGHT        = 0;
const unsigned int TOP_RIGHT    = 1;
const unsigned int TOP          = 2;
const unsigned int TOP_LEFT     = 3;
const unsigned int LEFT         = 4;
const unsigned int BOTTOM_LEFT  = 5;
const unsigned int BOTTOM       = 6;
const unsigned int BOTTOM_RIGHT = 7;

bool isOutOfBoard(float x, float y, float w, float h, unsigned int *spot) {
	if (x < 0) {
		if (spot != nullptr) *spot = LEFT;
		return true;
	}
	else if (y < 0) {
		if (spot != nullptr) *spot = TOP;
		return true;
	}
	else if (x + w >= BOARD_WIDTH) {
		if (spot != nullptr) *spot = RIGHT;
		return true;
	}
	else if (y + h >= BOARD_HEIGHT) {
		if (spot != nullptr) *spot = BOTTOM;
		return true;

	}
	return false;
}

bool isOutOfBoard(float x, float y, unsigned int *spot) {
	return isOutOfBoard(x, y, 0, 0, spot);
}

bool collisionRight(float x1, float w1, float x2) {
	return (x1 < x2 && x1 + w1 > x2);
}

bool collisionLeft(float x1, float x2, float w2) {
	return (x1 > x2 && x2 + w2 > x1);
}

bool collisionDown(float y1, float h1, float y2) {
	return (y2 > y1 && y1 + h1 > y2);
}

bool collisionUp(float y1, float y2, float h2) {
	return (y1 > y2 && y2 + h2 > y1);
}

bool collision(float x1, float y1, float w1, float h1,
	float x2, float y2, float w2, float h2,
	unsigned int *spot) {

	bool collideL, collideR, collideD, collideU;
	collideL = collisionLeft(x1, x2, w2);
	collideR = collisionRight(x1, w1, x2);
	collideU = collisionUp(y1, y2, h2);
	collideD = collisionDown(y1, h1, y2);

	// right
	if (collideR) {
		// just right
		if (collideD && collideU) {
			*spot = RIGHT;
			return true;
		}
		// top right
		else if (collideU && !collideD) {
			*spot = TOP_RIGHT;
			return true;
		}
		// bottom_right
		else if (collideD && !collideU) {
			*spot = BOTTOM_RIGHT;
			return true;
		}
	}
	// left
	else if (collideL) {
		// just left
		if (collideD && collideU) {
			*spot = LEFT;
			return true;
		}
		// top left
		else if (collideU && !collideD) {
			*spot = TOP_LEFT;
			return true;
		}
		// bottom left
		else if (collideD && !collideU) {
			*spot = BOTTOM_LEFT;
			return true;
		}
	}
	// up
	else if (collideU && (collideL && collideR)) {
		*spot = TOP;
		return true;
	}
	// down
	else if (collideU && (collideL && collideR)) {
		*spot = BOTTOM;
		return true;
	}
	return false;
}

