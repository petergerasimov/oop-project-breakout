#include "game.hpp"
#include "collisions.hpp"

// Use scale factor
Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	ball = Ball(window); //Maybe add a method setWindow();
	paddle = Paddle(window);

	//Vector2D dir = {1, 1};
	ball.setVelocity(0.01);
	ball.setDir({1, 1});
	ball.setPos({400, 300});

	paddle.setVelocity(0.1);
	paddle.setPos({400, 780});
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
	//

	bool test = colls::circleRectangle({ball.getX(), ball.getY(), ball.getRadius()},
						   			   {paddle.getX(), paddle.getY(), paddle.getWidth(), paddle.getHeight()});

	if(test) {
		Vector2D dir = ball.getDir();
		dir.y = -dir.y;
		ball.setDir(dir);
	}


	ball.update();
	paddle.update();
}