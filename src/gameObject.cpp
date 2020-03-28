#include "gameObject.hpp"

GameObject::GameObject()
{
	x = y = 0;
}

GameObject::GameObject(float x, float y)
{
	this->x = x;
	this->y = y;
}

GameObject::~GameObject()
{

}

void GameObject::setX(float x)
{
	this->x = x;
}

void GameObject::setY(float y)
{
	this->y = y;
}

void GameObject::setXY(float x, float y)
{
	this->x = x;
	this->y = y;
}

float GameObject::getX()
{
	return x;
}

float GameObject::getY()
{
	return y;
}

void update()
{
	draw();
	//isColliding();
}