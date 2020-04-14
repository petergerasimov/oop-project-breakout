#include "brick.hpp"

Brick::Brick()
{
	std::cout << "Brick created";
}

Brick::Brick(sf::RenderWindow* window)
{
	this->window = window;

	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setFillColor(sf::Color::White);

	if(!shapeTexture.loadFromFile("content/brick.png"))
		std::cout << "Texture not loaded!";
}

Brick::~Brick()
{
	std::cout << "Brick destroyed!";
}

//Setters
void Brick::setWidth(float width)
{
	this->width = width;
	shape.setSize(sf::Vector2f(this->width, this->height));
}

void Brick::setHeight(float height)
{
	this->height = height;
	shape.setSize(sf::Vector2f(this->width, this->height));
}

//Getters
float Brick::getWidth()
{
	return this->width;
}

float Brick::getHeight()
{
	return this->height;
}

void Brick::draw()
{
	shape.setPosition(getX(), getY());
	shape.setTexture(&shapeTexture);
	window->draw(shape);

}

void Brick::update()
{
	draw();
}