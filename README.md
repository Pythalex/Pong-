# Pong++
Pong clone in C++ with OpenGL3.3 and GLFW

---------------

![alt tag](https://i.gyazo.com/e48092df70321e3e5cac11034ac97bbb.png) 

### Prerequesites

glad : [https://github.com/Dav1dde/glad](https://github.com/Dav1dde/glad) (or the [webservice](http://glad.dav1d.de/), choose C++, OpenGL, Profile Core)

glfw : [http://www.glfw.org/](http://www.glfw.org/) Download last version

With your IDE (or by your own), add include directories of glad and glfw, add glad.c to your project. Follow the [glfw compilation guide](http://www.glfw.org/docs/latest/compile_guide.html) to get the binaries for your system.

### How it works

window, shader, and graphics implement the basics functions to draw. For now, only two primitives are available (drawTriangle and drawRectangle). Everything for the game system is written in game.cpp (update and draw) and in Piece/Ball classes. 

The math module implements trivial vector manipulations such as symmetry/rotation used in for ball bounce.

The ball movement is calculated with an normalized vector (Ball::angleX, Ball::angleY) and Ball::speed simply by multiplicating the vector by the speed. player1 currently describes the human, and player2 the automatic player. Each update, if the player1 press KEY\_UP or KEY\_DOWN, the stick moves vertically, the automatic player moves according to the ball position versus its own. The autoplayer is far from perfect, but it's not so dumb and it works.

A human 2nd player system can be done simply by copying the player1 movement part for the player2 (but with a changement for the keys).

Each time the ball leave the board (left or right), reset() is called to reset the players and ball's position, angle and speed.

By default, the ball speed is increased by 0.5 each time a player hit it.

