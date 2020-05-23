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
		sf::Event* event;
		sf::Font font;
		sf::Text scoreText;
		sf::Text gameOverText;
		sf::Text playerNameText;
		//
		std::string playerName;
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
		sf::Vector2f ballStartPos;
		//Global velocity
		float gVelocity;

		sf::Vector2f getScreenCenter();

	public:
		Game(sf::RenderWindow* window, sf::Event* event);
		void gameScene();
		void onDeath();
		void scoreUpdate();
		void gameOverScene();
		void setup();
		void update();

};

#endif //__GAME_HPP