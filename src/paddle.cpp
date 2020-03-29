#include "paddle.hpp"

Paddle::Paddle()
{
	std::cout << "Paddle created";
}

Paddle::Paddle(sf::RenderWindow* window)
{
	this->window = window;

	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setFillColor(sf::Color::White);

	if(!shapeTexture.loadFromFile("content/sfml.png"))
		std::cout << "Texture not loaded!";
}

void Paddle::draw()
{
	shape.setPosition(getX(), getY());
	shape.setTexture(&shapeTexture);
	window->draw(shape);

}

void Paddle::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		setX(getX() - getVelocity());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		setX(getX() + getVelocity());
	}
}

void Paddle::update()
{
	input();
	updatePos();
	draw();
}