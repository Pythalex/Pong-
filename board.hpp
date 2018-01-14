#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INLCUDED

extern const int BOARD_WIDTH;
extern const int BOARD_HEIGHT;

extern const unsigned int RIGHT;
extern const unsigned int TOP_RIGHT;
extern const unsigned int TOP;
extern const unsigned int TOP_LEFT;
extern const unsigned int LEFT;
extern const unsigned int BOTTOM_LEFT;
extern const unsigned int BOTTOM;
extern const unsigned int BOTTOM_RIGHT;

/**
 * Indicates whether the bloc is out of the board
 * Indicates the leaving spot in the uint pointer, leave null if not interested.
 * (0 - right) (1 - left) (2 - up) (3 - down)
 * @param x coord
 * @param y coord
 * @param w width
 * @param h height
 * @return if the rectangle (x, y, x+w, y+h) is leaving the board
 */
bool isOutOfBoard(float x, float y, float w, float h, unsigned int *spot);

/**
* Same as isOutOfBoard but considering a point rather than a bloc.
* Calls isOutOfBoard(x, y, 0, 0);
* Indicates the leaving spot in the uint pointer, leave null if not interested.
* (0 - right) (1 - left) (2 - up) (3 - down)
* @param x coord
* @param y coord
* @return if the rectangle (x, y) is leaving the board
*/
bool isOutOfBoard(float x, float y, unsigned int *spot);

/**
 * Indicates whether the two blocs collided
 * @param x1 coord x of bloc 1
 * @param y1 coord y of bloc 1
 * @param w1 width of bloc 1
 * @param h1 heigth of bloc 1
 * @param x2 coord x of bloc 2
 * @param y2 coord y of bloc 2
 * @param w2 width of bloc 2
 * @param h2 heigth of bloc 2
 * @param spot variable containing the collision spot (in bloc 1 pov)
 *	 (0 right - 1 left - 2 up - 3 down) not modified if there isn't a collision
 * @return if (x1, y1, w1, h1) collides with (x2, y2, w2, h2)
 */
bool collision(float x1, float y1, float w1, float h1,
	float x2, float y2, float w2, float h2,
	unsigned int *spot);

#endif