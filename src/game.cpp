#include "game.hpp"

Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	ball = Ball(window); //Maybe add a method setWindow();
	Vector2D dir = {1, 1};
	ball.setDir(dir);
}

void Game::update()
{
	ball.update();
}