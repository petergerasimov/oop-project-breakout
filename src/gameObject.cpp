#include "gameObject.hpp"

GameObject::GameObject()
{
	//assert(window);
}

GameObject::GameObject(sf::RenderWindow* window)
{
	this->window = window;
}

GameObject::~GameObject()
{
	std::cout << "Game object destroyed!";
}

void GameObject::setX(float x)
{
	this->pos.x = x;
}

void GameObject::setY(float y)
{
	this->pos.y = y;
}

void GameObject::setPos(Point p)
{
	this->pos = p;
}

void GameObject::setDir(Vector2D dir)
{
	float eps = 0.0001;
	//Making sure the direction doesn't affect the speed;
	float divBy = std::sqrt(dir.x*dir.x + dir.y*dir.y);

	if(std::abs(divBy) < eps)
		return;

	this->dir.x = dir.x/divBy;
	this->dir.y = dir.y/divBy;
}

float GameObject::getX()
{
	return this->pos.x;
}

float GameObject::getY()
{
	return this->pos.y;
}

Point GameObject::getPos()
{
	return this->pos;
}

Vector2D GameObject::getDir()
{
	return this->dir;
}

void GameObject::updatePos()
{
	this->pos.x += this->dir.x * this->vel;
	this->pos.y += this->dir.y * this->vel;
}

void GameObject::update()
{
	updatePos();
}