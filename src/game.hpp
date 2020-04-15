#ifndef __GAME_HPP
#define __GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <vector>

class Game
{
	private:
		//SFML vars
		sf::RenderWindow* window;
		sf::Font font;
		sf::Text text;
		//Game objects
		Ball ball;
		Paddle paddle;
		std::vector<Brick> bricks;
		//Brick parameters
		int bricksPerRow = 6;
		int brickRows = 6;
		float brickPadding = 5;
		float brickOffset = 40;
		//Game vars
		int score = 0;
		int lives = 3;
		float initVelocity = 0.1;
		Point ballStartPos;
		//Global velocity
		float gVelocity;

	public:
		Game(sf::RenderWindow* window);
		void gameScene();
		void gameOverScene();
		void update();

};

#endif //__GAME_HPP