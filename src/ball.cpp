#include "ball.hpp"

Ball::Ball()
{
	std::cout << "testing";
}

Ball::Ball(sf::RenderWindow* window)
{
	this->window = window;

	shape.setRadius(this->radius);
	shape.setFillColor(sf::Color::White);

	if(!shapeTexture.loadFromFile("content/sfml.png"))
		std::cout << "Texture not loaded!";

}

void Ball::setRadius(float radius)
{
	this->radius = radius;
}

float Ball::getRadius()
{
	return this->radius;
}

void Ball::draw()
{
	shape.setPosition(getX(), getY());
	shape.setTexture(&shapeTexture);
	window->draw(shape);

}

void Ball::update()
{
	updatePos();
	draw();
}