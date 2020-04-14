#ifndef __GAME_HPP
#define __GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <vector>

class Game
{
	private:
		sf::RenderWindow* window;
		Ball ball;
		Paddle paddle;
		std::vector<Brick> bricks;
		int bricksPerRow = 6;
		int brickRows = 6;
		int brickPadding = 5;

	public:
		Game(sf::RenderWindow* window);
		void update();
};

#endif //__GAME_HPP