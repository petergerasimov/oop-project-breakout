#include "game.hpp"
#include <string>

Game::Game(sf::RenderWindow *window, sf::Event* event)
{
	this->window = window;
	this->event = event;
	//this fixes window resize issues
	width = (float)window->getSize().x;
	height = (float)window->getSize().y;

	if (!font.loadFromFile("content/FredokaOne-Regular.ttf"))
		std::cout << "Font not loaded";

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
	ball.setDir({0, 1});
	//adding 10 so the ball can go out of screen
	ball.setBoundingBox({0, 0, width, height + 10});
	ball.setPos(ballStartPos);

	paddle.setWidth(width / 5);
	paddle.setVelocity(gVelocity);
	paddle.setBoundingBox({0, 0, width, height});
	paddle.setPos({width / 2 - paddle.getWidth()/2,
				   height - 2 * paddle.getHeight()});

	//Placing all the bricks
	float brickWidth = width / bricksPerRow;
	float brickHeight = brickWidth / 6;
	float xOff = 2.5f;
	for (int i = 0; i < bricksPerRow; i++)
	{
		for (int j = 0; j < brickRows; j++)
		{
			bricks.push_back(Brick(window));
			int index = i * brickRows + j;
			bricks[index].setWidth(brickWidth - brickPadding);
			bricks[index].setHeight(brickHeight);
			float x = xOff + i * brickWidth;
			float y = j * (bricks[index].getHeight() + brickPadding) + brickOffset;
			bricks[index].setPos({x, y});
		}
	}




	std::vector<sf::Text*> texts = {&scoreText, &gameOverText, &playerNameText};
	for(auto &t : texts)
	{
		t->setFont(font);
		t->setCharacterSize(brickOffset / 2);
	}
	gameOverText.setPosition(getScreenCenter());
	//This fixes a bug after reseting the game
	//Because the velocities change as a function of the elapsed time
	//If you wait too much on the loading screen the speed gets really big
	clock.restart();
}

void Game::gameScene()
{

	if (ball.getY() >= height - ball.getRadius())
		onDeath();

	ball.collRect(paddle.getRect());

	//auto for loop caused crashes sometimes
	int sz = bricks.size();
	for(int i = 0; i < sz; i++)
	{
		if(ball.collRect(bricks[i].getRect()))
		{
			//Destroy brick
			bricks[i] = bricks[sz - 1];
			bricks.pop_back();
			sz--;

			scoreUpdate();
		}
		bricks[i].update();
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
	ball.setDir({0, 1});
	lives--;
}

void Game::scoreUpdate()
{
	score += 100 * gVelocity;
	gVelocity += 0.025;
	paddle.setVelocity(gVelocity);
	ball.setVelocity(gVelocity);
}

std::string Game::enterText()
{
	static sf::Clock textClock;
	static std::string toReturn;
	if (event->type == sf::Event::TextEntered)
	{
		//If someone somehow types a non-ascii symbol it will be displayed as a #
		char c = '#';
		static char last = 0;

		if(event->text.unicode < 128)
		{
			c = (char)event->text.unicode;
		}

		if (last != c || clock.getElapsedTime().asMilliseconds() > 175)
		{
			if (c == '\b')
			{
				if (!toReturn.empty())
				{
					toReturn.pop_back();
				}
			}
			else
			{
				toReturn.push_back(c);

			}
			last = c;
			clock.restart();
		}
	}
	return toReturn;
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
		char c = (char)event->text.unicode;
		if(c == '\r' || c == '\n')
			setup();
	}

	playerName = enterText();

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
