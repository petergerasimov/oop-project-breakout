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
	//std::cout << "Game object destroyed!";
}

//Setters
void GameObject::setX(float x)
{
	this->pos.x = x;
}

void GameObject::setY(float y)
{
	this->pos.y = y;
}

void GameObject::setPos(sf::Vector2f p)
{
	this->pos = p;
}

void GameObject::setDir(sf::Vector2f dir)
{
	float eps = 0.0001;
	//Making sure the direction doesn't affect the speed;
	float divBy = std::sqrt(dir.x*dir.x + dir.y*dir.y);

	if(std::abs(divBy) < eps)
		return;

	this->dir.x = dir.x/divBy;
	this->dir.y = dir.y/divBy;
}

void GameObject::setDir(float angle)
{
	this->dir.x = std::cos(angle);
	this->dir.y = std::sin(angle);
}

void GameObject::setVelocity(float vel)
{
	this->vel = vel;
}

void GameObject::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}
void GameObject::setBoundingBox(Rect boundingBox)
{
	this->boundingBox = boundingBox;
}
void GameObject::setTexture(std::string filename)
{
	if(!shapeTexture.loadFromFile(filename))
		std::cout << "Texture not loaded!";
}


//Getters
float GameObject::getX() const
{
	return this->pos.x;
}

float GameObject::getY() const
{
	return this->pos.y;
}

sf::Vector2f GameObject::getPos() const
{
	return this->pos;
}

sf::Vector2f GameObject::getDir() const
{
	return this->dir;
}

float GameObject::getVelocity() const
{
	return this->vel;
}

sf::RenderWindow* GameObject::getWindow() const
{
	return window;
}

Rect GameObject::getBoundingBox() const
{
	return boundingBox;
}

sf::Texture* GameObject::getTexture()
{
	return &shapeTexture;
}


void GameObject::updatePos()
{
	this->pos.x += this->dir.x * this->vel;
	this->pos.y += this->dir.y * this->vel;
}

void GameObject::update()
{
	checkBounds();
	updatePos();
	draw();
}

void GameObject::draw()
{
	std::cout << "drawing" << std::endl;
}

void GameObject::checkBounds()
{
	//std::cout << "checking bounds";
}