#include "game.hpp"
#include "collisions.hpp"

// Use scale factor
Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	ball = Ball(window); //Maybe add a method setWindow();
	paddle = Paddle(window);


	//Vector2D dir = {1, 1};
	ball.setVelocity(0.2);
	ball.setDir({1, 3});
	ball.setPos({400, 300});

	paddle.setWidth(window->getSize().x / 5);
	paddle.setVelocity(0.2);
	paddle.setPos({400, 780});

	float brickWidth = window->getSize().x / bricksPerRow;
	float brickHeight = brickWidth / 6;
	for(int i = 0; i < bricksPerRow ; i++)
	{
		for(int j = 0; j < brickRows; j++)
		{
			bricks.push_back(Brick(window));
			int index = i*brickRows + j;
			bricks[index].setWidth(brickWidth - brickPadding);
			bricks[index].setHeight(brickHeight);
			bricks[index].setPos({i*brickWidth, j*(bricks[index].getHeight() + brickPadding)});
		}
	}


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

	bool isPaddleHit = colls::circleRectangle({ball.getX(),
											   ball.getY(),
										       ball.getRadius()},
						   			          {paddle.getX(),
										       paddle.getY(),
										       paddle.getWidth(),
										       paddle.getHeight()});

	if(isPaddleHit) {
		Vector2D dir = ball.getDir();
		dir.y = -dir.y;
		ball.setDir(dir);
	}

	for(auto& b : bricks)
	{
		bool isBrickHit = colls::circleRectangle({ball.getX(),
												  ball.getY(),
												  ball.getRadius()},
						   			        	 {b.getX(),
										    	  b.getY(),
												  b.getWidth(),
												  b.getHeight()});

		if(isBrickHit)
		{
			Vector2D dir = ball.getDir();
			dir.y = -dir.y;
			ball.setDir(dir);

			//Destroy brick
			b = bricks.back();
			bricks.pop_back();
		}
		b.update();
	}
	ball.update();
	paddle.update();

}