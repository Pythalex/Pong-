#ifndef BALL_HPP_INCLUDED
#define BALL_HPP_INCLUDED

#include "Piece.hpp"

class Ball : public Piece {
public:

	/// CONSTRUCTOR

	/**
	 * Default constructor, everything is set to 0.
	 */
	Ball();

	/** 
	 * Standard piece with (1,0) as angle
	 */
	Ball(float x, float y, float w, float h);

	/**
	 * Standard piece with given angle
	 */
	Ball(float x, float y, float w, float h, float angleX, float angleY);

	/**
	* Standard piece with given angle and speed
	*/
	Ball(float x, float y, float w, float h, float angleX, float angleY, float speed);

	/// METHODS

	/**
	 * Bounce given a collision side.
	 * 0 - right
	 * 1 - left
	 * 2 - up
	 * 3 - down
	 * @param side : the collision side
	 */
	void bounce(unsigned int side);

	/// ATTRIBUTES

	float angleX;
	float angleY;
	float speed;
};


#endif