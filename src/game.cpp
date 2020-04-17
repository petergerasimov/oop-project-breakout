#include "game.hpp"
#include "collisions.hpp"
#include <string>

//TODO: Use scale factor
Game::Game(sf::RenderWindow* window)
{
	//Making sure all the objects are drawn on the same window
	this->window = window;
	ball.setWindow(window);
	paddle.setWindow(window);


	gVelocity = initVelocity;
	//Setting some initial values
	ball.setVelocity(gVelocity);
	ball.setDir({1, 3});
	ballStartPos = {(float)window->getSize().x / 2,
				 	(float)window->getSize().y / 2};
	ball.setPos(ballStartPos);
	//ball.setRadius(40);

	paddle.setWidth(window->getSize().x / 5);
	paddle.setVelocity(gVelocity);
	paddle.setPos({400, 780});

	//Placing all the bricks
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
			float x = i*brickWidth;
			float y = j*(bricks[index].getHeight() + brickPadding) + brickOffset;
			bricks[index].setPos({x, y});
		}
	}


	if (!font.loadFromFile("content/FredokaOne-Regular.ttf"))
		std::cout << "Font not loaded";

	text.setFont(font);
	text.setCharacterSize(brickOffset / 2);
	text.setFillColor(sf::Color::White);


}

void Game::gameScene()
{
	//Collisions with screen TODO: Make better
	if(ball.getX() >= window->getSize().x || ball.getX() <= 0)
		ball.reverseDirX();

	if(ball.getY() <= 0)
		ball.reverseDirY();

	if(ball.getY() >= window->getSize().y)
	{
		ball.reverseDirY();

		//Death -- reset positions
		gVelocity = initVelocity;
		ball.setVelocity(gVelocity);
		ball.setPos(ballStartPos);
		paddle.setVelocity(gVelocity);
		lives--;

	}
	//

	//Collisions with paddle
	bool isPaddleHit = colls::circleRectangle(ball.getCircle(),
											  paddle.getRect());

	if(isPaddleHit)
		ball.reverseDirY();
	//

	//Collisons with bricks
	for(auto& b : bricks)
	{
		bool isBrickHit = colls::circleRectangle(ball.getCircle(),
											  	 b.getRect());

		if(isBrickHit)
		{
			ball.reverseDirY();
			//Destroy brick
			b = bricks.back();
			bricks.pop_back();

			score+=100 * gVelocity;
			gVelocity+=0.01;
			paddle.setVelocity(gVelocity);
			ball.setVelocity(gVelocity);
		}
		b.update();
	}
	//

	ball.update();
	paddle.update();
	text.setString("Score: " + std::to_string(score) +
				   " Lives: " + std::to_string(lives));
	window->draw(text);
}

void Game::gameOverScene()
{
	text.setString("Game over! Score:" + std::to_string(score));
	window->draw(text);
}

void Game::update()
{
	if(lives > 0 && bricks.size() > 0)
		gameScene();
	else
		gameOverScene();
}