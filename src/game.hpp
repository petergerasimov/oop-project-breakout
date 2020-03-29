#ifndef __GAME_HPP
#define __GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"

class Game
{
	private:
		sf::RenderWindow* window;
		Ball ball;
		Paddle paddle;
	public:
		Game(sf::RenderWindow* window);
		void update();
};

#endif //__GAME_HPP