#include "game.hpp"
#include <string>

Game::Game(sf::RenderWindow *window, sf::Event* event)
{
	this->window = window;
	this->event = event;
	setup();
}

sf::Vector2f Game::getScreenCenter()
{
	return {(float)window->getSize().x / 2,
			(float)window->getSize().y / 2};
}

void Game::setup()
{
	//Making sure all the objects are drawn on the same window
	ball.setWindow(window);
	paddle.setWindow(window);

	//Setting some initial values
	lives = 3;
	score = 0;
	gVelocity = initVelocity = 0.15;

	ball.setVelocity(gVelocity);
	ball.setDir({1, 3});
	//ball.setDir(-2.0f);
	ballStartPos = getScreenCenter();
	ball.setPos(ballStartPos);

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


	std::vector<sf::Text*> texts = {&scoreText, &gameOverText, &playerNameText};
	for(auto &t : texts)
	{
		t->setFont(font);
		t->setCharacterSize(brickOffset / 2);
	}
	gameOverText.setPosition(getScreenCenter());
}

void Game::gameScene()
{
	//Collisions with screen
	if (ball.getX() >= window->getSize().x || ball.getX() <= 0)
		ball.reverseDirX();

	if (ball.getY() <= 0)
		ball.reverseDirY();

	if (ball.getY() >= window->getSize().y)
	{
		onDeath();
	}

	ball.collRect(paddle.getRect());

	for (auto &b : bricks)
	{
		if(ball.collRect(b.getRect()))
		{
			//Destroy brick
			b = bricks.back();
			bricks.pop_back();

			scoreUpdate();
		}
		b.update();
	}

	//
	// ball.setX(sf::Mouse::getPosition().x);
	// ball.setY(sf::Mouse::getPosition().y);
	//
	ball.update();
	paddle.update();
	scoreText.setString("Score: " + std::to_string(score) +
						" Lives: " + std::to_string(lives));
	window->draw(scoreText);
}

void Game::onDeath()
{
	gVelocity = initVelocity;
	ball.setVelocity(gVelocity);
	ball.setPos(ballStartPos);
	paddle.setVelocity(gVelocity);
	lives--;
}

void Game::scoreUpdate()
{
	score += 100 * gVelocity;
	gVelocity += 0.01;
	paddle.setVelocity(gVelocity);
	ball.setVelocity(gVelocity);
}

void Game::gameOverScene()
{
	float width = gameOverText.getLocalBounds().width;
	gameOverText.setOrigin(width / 2, 0);
	gameOverText.setString("Game over!\nScore: " + std::to_string(score));

	playerNameText.setOrigin(width / 2, 0);
	playerNameText.setPosition({(float)window->getSize().x / 2,
	 							gameOverText.getPosition().y + gameOverText.getLocalBounds().height + 10});


	if (event->type == sf::Event::TextEntered)
	{
		//If someone somehow types a non-ascii symbol it will be displayed as a #
		char c = '#';

		if(event->text.unicode < 128)
		{
			c = (char)event->text.unicode;
		}

		if(c == '\b')
		{
			if(!playerName.empty())
			{
				playerName.pop_back();
			}
		}
		else if(c == '\r' || c == '\n')
		{
			setup();
		}
		else
		{
			playerName.push_back(c);
		}


		sf::Time t = sf::milliseconds(120);
		sf::sleep(t);
	}
	if(playerName.empty())
	{
		playerNameText.setString("Type name");
	}
	else
	{
		playerNameText.setString(playerName);
	}
	window->draw(playerNameText);
	window->draw(gameOverText);
}

void Game::update()
{
	if (lives > 0 && bricks.size() > 0)
	{
		gameScene();
	}
	else
	{
		if(!bricks.empty())
		{
			bricks.clear();
		}
		gameOverScene();
	}

}