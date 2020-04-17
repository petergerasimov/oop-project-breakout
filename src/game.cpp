#include "game.hpp"
#include "collisions.hpp"
#include <string>

Game::Game(sf::RenderWindow *window, sf::Event* event)
{
	this->window = window;
	this->event = event;
	setup();
}

void Game::setup()
{
	//Making sure all the objects are drawn on the same window
	ball.setWindow(window);
	paddle.setWindow(window);

	//Setting some initial values
	lives = 1;
	score = 0;
	gVelocity = initVelocity;

	ball.setVelocity(gVelocity);
	ball.setDir({1, 3});
	ballStartPos = {(float)window->getSize().x / 2,
					(float)window->getSize().y / 2};
	ball.setPos(ballStartPos);
	//ball.setRadius(40);

	paddle.setWidth(window->getSize().x / 5);
	paddle.setVelocity(gVelocity);
	paddle.setPos({(float)window->getSize().x / 2,
				   (float)window->getSize().y - 2 * paddle.getHeight()});

	//Placing all the bricks
	float brickWidth = window->getSize().x / bricksPerRow;
	float brickHeight = brickWidth / 6;
	for (int i = 0; i < bricksPerRow; i++)
	{
		for (int j = 0; j < brickRows; j++)
		{
			bricks.push_back(Brick(window));
			int index = i * brickRows + j;
			bricks[index].setWidth(brickWidth - brickPadding);
			bricks[index].setHeight(brickHeight);
			float x = i * brickWidth;
			float y = j * (bricks[index].getHeight() + brickPadding) + brickOffset;
			bricks[index].setPos({x, y});
		}
	}

	if (!font.loadFromFile("content/FredokaOne-Regular.ttf"))
		std::cout << "Font not loaded";

	scoreText.setFont(font);
	scoreText.setCharacterSize(brickOffset / 2);
	scoreText.setFillColor(sf::Color::White);

	gameOverText.setFont(font);
	gameOverText.setCharacterSize(brickOffset / 2);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setPosition({(float)window->getSize().x / 2,
							  (float)window->getSize().y / 2});

	playerNameText.setFont(font);
	playerNameText.setCharacterSize(brickOffset / 2);
	playerNameText.setFillColor(sf::Color::White);
}

void Game::gameScene()
{
	//Collisions with screen TODO: Make better
	if (ball.getX() >= window->getSize().x || ball.getX() <= 0)
		ball.reverseDirX();

	if (ball.getY() <= 0)
		ball.reverseDirY();

	if (ball.getY() >= window->getSize().y)
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

	if (isPaddleHit)
		ball.reverseDirY();
	//

	//Collisons with bricks
	for (auto &b : bricks)
	{
		bool isBrickHit = colls::circleRectangle(ball.getCircle(),
												 b.getRect());

		if (isBrickHit)
		{
			ball.reverseDirY();
			//Destroy brick
			b = bricks.back();
			bricks.pop_back();

			score += 100 * gVelocity;
			gVelocity += 0.01;
			paddle.setVelocity(gVelocity);
			ball.setVelocity(gVelocity);
		}
		b.update();
	}
	//

	ball.update();
	paddle.update();
	scoreText.setString("Score: " + std::to_string(score) +
						" Lives: " + std::to_string(lives));
	window->draw(scoreText);
}

void Game::gameOverScene()
{
	float width = gameOverText.getLocalBounds().width;
	gameOverText.setOrigin(width / 2, 0);
	gameOverText.setString("Game over!\nScore: " + std::to_string(score) +
						   "Name: ");

	playerNameText.setOrigin(width / 2, 0);
	playerNameText.setPosition({(float)window->getSize().x / 2,
								(gameOverText.getOrigin().y + gameOverText.getLocalBounds().y});


	if (event->type == sf::Event::TextEntered)
	{
		if(event->text.unicode != '\b')
		{
			if(event->text.unicode < sizeof(char) * 8)
			{
				playerName += (char)event->text.unicode;
			}

		}
		else
		{
			if(!playerName.empty())
				playerName.pop_back();
		}


		playerNameText.setString(playerName);
		sf::Time t = sf::milliseconds(120);
		sf::sleep(t);
	}
	window->draw(playerNameText);
	window->draw(gameOverText);
}

void Game::update()
{
	if (lives > 0 && bricks.size() > 0)
		gameScene();
	else
		gameOverScene();
}