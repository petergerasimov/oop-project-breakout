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
		sf::Clock clock;
		//window size vars
		float width;
		float height;
		//Game objects
		Ball ball;
		Paddle paddle;
		std::vector<Brick> bricks;
		//Game vars
		int score = 0;
		std::string playerName;
		int highScore = 0;
		std::string hsHolder;
		int lives = 3;
		float initVelocity = 0.1;
		sf::Vector2f ballStartPos;
		//Global velocity
		float gVelocity;

		sf::Vector2f getScreenCenter();
		float getDeltaTime();
		//Making the game play the same on different computers
		void updateVelocities();
		std::string enterText();
		void saveHighScore(const char *file);
		void loadHighScore(const char *file);
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