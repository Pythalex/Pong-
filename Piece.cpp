#include "Piece.hpp"

#include "board.hpp"

Piece::Piece() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Piece::Piece(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Piece::collideWith(Piece p, unsigned int *spot) {
	return collision(x, y, w, h, p.x, p.y, p.w, p.h, spot);
}

bool Piece::collideWith(Piece p) {
	unsigned int dontcare = 0;
	return collision(x, y, w, h, p.x, p.y, p.w, p.h, &dontcare);
}

bool Piece::move(float dx, float dy, unsigned int *spot) {

	if (isOutOfBoard(x + dx, y + dy, w, h, spot)) {
		return false;
	}
	else {
		x += dx;
		y += dy;
		return true;
	}
}

