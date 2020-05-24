#include "brick.hpp"

Brick::Brick()
{
	init();
}

Brick::Brick(sf::RenderWindow* window)
{
	setWindow(window);
	init();
}

Brick& Brick::operator=(const Brick& b)
{
    setX(b.getX());
    setY(b.getY());
    setWidth(b.getWidth());
    setHeight(b.getHeight());
	setWindow(b.getWindow());
    return *this;
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
float Brick::getWidth() const
{
	return this->width;
}

float Brick::getHeight() const
{
	return this->height;
}

Rect Brick::getRect()
{
	Rect r = {getX(), getY(), width, height};
	return r;
}

void Brick::draw()
{
	shape.setPosition(getX(), getY());
	shape.setTexture(&shapeTexture);
	getWindow()->draw(shape);

}

void Brick::init()
{
	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setFillColor(sf::Color::White);

	if(!shapeTexture.loadFromFile("content/brick.png"))
		std::cout << "Texture not loaded!";
}