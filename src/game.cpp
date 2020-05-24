#include "game.hpp"
#include <string>

Game::Game(sf::RenderWindow *window, sf::Event* event)
{
	this->window = window;
	this->event = event;
	//this fixes window resize issues
	width = (float)window->getSize().x;
	height = (float)window->getSize().y;
	setup();
}

sf::Vector2f Game::getScreenCenter()
{
	return {width / 2, height / 2};
}

float Game::getDeltaTime()
{
    float timeDifference = clock.getElapsedTime().asSeconds();
    clock.restart();
	return timeDifference;
}

void Game::updateVelocities()
{
	const float normal = 1.0f / 1200; //On my machine the game runs on about 1200 fps
	float vel = gVelocity * getDeltaTime() / normal;
	ball.setVelocity(vel);
	paddle.setVelocity(vel);
}

void Game::setup()
{
	//Making sure all the objects are drawn on the same window
	ball.setWindow(window);
	paddle.setWindow(window);

	//Setting some initial values
	lives = 3;
	score = 0;
	gVelocity = initVelocity = 0.25;
	ballStartPos = getScreenCenter();

	ball.setVelocity(gVelocity);
	ball.setDir({1, 3});
	//adding 10 so the ball can go out of screen
	ball.setBoundingBox({0, 0, width, height + 10});
	ball.setPos(ballStartPos);

	paddle.setWidth(width / 5);
	paddle.setVelocity(gVelocity);
	paddle.setBoundingBox({0, 0, width, height});
	paddle.setPos({width / 2,
				   height - 2 * paddle.getHeight()});

	//Placing all the bricks
	float brickWidth = width / bricksPerRow;
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

	if (ball.getY() >= height)
		onDeath();

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

	updateVelocities();
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
	gVelocity += 0.025;
	paddle.setVelocity(gVelocity);
	ball.setVelocity(gVelocity);
}

void Game::gameOverScene()
{
	float textWidth = gameOverText.getLocalBounds().width;
	gameOverText.setOrigin(textWidth / 2, 0);
	gameOverText.setString("Game over!\nScore: " + std::to_string(score));

	playerNameText.setOrigin(textWidth / 2, 0);
	playerNameText.setPosition({width / 2,
	 							gameOverText.getPosition().y +
								gameOverText.getLocalBounds().height + 10 });


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
