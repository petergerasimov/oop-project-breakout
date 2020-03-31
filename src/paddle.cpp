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

	if(!shapeTexture.loadFromFile("content/brick.png"))
		std::cout << "Texture not loaded!";
}

//Setters
void Paddle::setWidth(float width)
{
	this->width = width;
}

void Paddle::setHeight(float height)
{
	this->height = height;
}

//Getters
float Paddle::getWidth()
{
	return this->width;
}

float Paddle::getHeight()
{
	return this->height;
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