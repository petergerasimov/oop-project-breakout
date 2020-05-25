#include "paddle.hpp"

Paddle::Paddle()
{
	init();
}

Paddle::Paddle(sf::RenderWindow* window)
{
	setWindow(window);
	init();
}

//Setters
void Paddle::setWidth(float width)
{
	this->width = width;
	shape.setSize(sf::Vector2f(this->width, this->height));
}

void Paddle::setHeight(float height)
{
	this->height = height;
	shape.setSize(sf::Vector2f(this->width, this->height));
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

Rect Paddle::getRect()
{
	Rect r = {getX(), getY(), width, height};
	return r;
}


void Paddle::draw()
{
	shape.setPosition(getX(), getY());
	shape.setTexture(getTexture());
	getWindow()->draw(shape);
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

void Paddle::checkBounds()
{
	Rect b = getBoundingBox();
	if(getX() < b.x)
	{
		setX(b.x);
	}
	else if(getX() > b.w - getWidth())
	{
		setX(b.w - getWidth());
	}
}

void Paddle::updatePos()
{
	input();
	GameObject::updatePos();
}


void Paddle::init()
{
	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setFillColor(sf::Color::White);
}