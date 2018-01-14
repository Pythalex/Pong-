#ifndef PIECE_HPP_INCLUDED
#define PIECE_HPP_INCLUDED

class Piece {

public:

	/// CONSTRUCTOR

	/**
	 * Default constructor, everything is set to 0.
	 */
	Piece();

	/** 
	 * Creates a piece of given coordinates.
	 * @param x coord
	 * @param y coord
	 * @param w width
	 * @param h height
	 */
	Piece(float x, float y, float w, float h);

	/// METHODS

	/** 
	 * Indicates whether the piece collides with the given piece.
	 * The collision spot is return as pointer.
	 * @param p Piece to test collision with
	 * @return if this collides with p
	 */
	bool collideWith(Piece p, unsigned int *spot);

	/**
	* Indicates whether the piece collides with the given piece.
	* Same as collideWith(Piece p, unsigned int *spot) but don't care
	* of the spot.
	* @param p Piece to test collision with
	* @return if this collides with p
	*/
	bool collideWith(Piece p);

	/**
	 * Try to move the piece by the given translation
	 * if the movement is possible, it's done and returns true,
	 * else the movement is undone and returns false.
	 * @param dx the x translation
	 * @param dy the y translation
	 * @return if the movement is possible.
	 */
	bool move(float dx, float dy, unsigned int *spot);

	/// ATTRIBUTE

	float x;
	float y;
	float w;
	float h;

};

#endif