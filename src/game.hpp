#ifndef __GAME_HPP
#define __GAME_HPP

#include "ball.hpp"

class Game
{
	private:
		sf::RenderWindow* window;
		Ball ball;
	public:
		Game(sf::RenderWindow* window);
		void update();
};

#endif //__GAME_HPP