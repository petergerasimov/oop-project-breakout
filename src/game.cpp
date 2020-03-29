#include "game.hpp"

Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	ball = Ball(window); //Maybe add a method setWindow();
	paddle = Paddle(window);

	Vector2D dir = {1, 1};
	ball.setVelocity(0.1);
	ball.setDir(dir);
	Point a = {400, 300};
	ball.setPos(a);

	paddle.setVelocity(0.1);
}

void Game::update()
{
	//Collisions with screen
	if(ball.getX() >= window->getSize().x || ball.getX() <= 0)
	{
		Vector2D dir = ball.getDir();
		dir.x = -dir.x;
		ball.setDir(dir);
	}

	if(ball.getY() >= window->getSize().y || ball.getY() <= 0)
	{
		Vector2D dir = ball.getDir();
		dir.y = -dir.y;
		ball.setDir(dir);
	}

	ball.update();
	paddle.update();
}