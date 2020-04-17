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
	shape.setTexture(&shapeTexture);
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

void Paddle::update()
{
	input();
	updatePos();
	draw();
}


void Paddle::init()
{
	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setFillColor(sf::Color::White);

	if(!shapeTexture.loadFromFile("content/paddle.png"))
		std::cout << "Texture not loaded!";
}