#include "game.hpp"

Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	shape.setRadius(50);
	shape.setFillColor(sf::Color::White);

	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);
}

void Game::update()
{
	window->draw(shape);
}