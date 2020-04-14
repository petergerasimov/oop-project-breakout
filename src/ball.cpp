#include "ball.hpp"

Ball::Ball()
{
	init();
}

Ball::Ball(sf::RenderWindow* window)
{
	setWindow(window);
	init();
}
//Setters
void Ball::setRadius(float radius)
{
	this->radius = radius;
}
//Getters
float Ball::getRadius()
{
	return this->radius;
}

Circle Ball::getCircle()
{
	Circle c = {getX(), getY(), radius};
	return c;
}

void Ball::init()
{
	shape.setRadius(this->radius);
	shape.setFillColor(sf::Color::White);

	if(!shapeTexture.loadFromFile("content/ball.png"))
		std::cout << "Texture not loaded!";
}
void Ball::draw()
{
	shape.setPosition(getX(), getY());
	shape.setTexture(&shapeTexture);
	getWindow()->draw(shape);
}

void Ball::update()
{
	updatePos();
	draw();
}