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
	shape.setRadius(this->radius);
	shape.setOrigin({this->radius, this->radius});
}
//Getters
float Ball::getRadius()
{
	return this->radius;
}

Circle Ball::getCircle()
{
	return Circle({getX(), getY(), radius});
}

void Ball::init()
{
	shape.setRadius(this->radius);
	shape.setOrigin({this->radius, this->radius});
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
float Ball::map(float x, float a, float b, float c, float d)
{
	return c + ((x-a)/(b-a))*(d-c);
}


void Ball::reverseDirX()
{
	setDir({-getDir().x, getDir().y});
}

void Ball::reverseDirY()
{
	setDir({getDir().x ,-getDir().y});
}

bool Ball::collRect(Rect rect)
{
	bool toReturn = false;
	float closestX;
	float closestY;
	closestX = std::abs(getX() - rect.x ) < std::abs(getX() - (rect.x + rect.w) ) ? rect.x : (rect.x + rect.w);
	closestY = std::abs(getY() - rect.y ) < std::abs(getY() - (rect.y + rect.h) ) ? rect.y : (rect.y + rect.h);

	bool inX = false;
	bool inY = false;

	if(closestX < getX())
		inX = getX() + radius > rect.x && getX() - radius < rect.x + rect.w;
	else
		inX = getX() - radius > rect.x && getX() + radius < rect.x + rect.w;

	if(closestY < getY())
		inY = getY() + radius > rect.y && getY() - radius < rect.y + rect.h;
	else
		inY = getY() - radius > rect.y && getY() + radius < rect.y + rect.h;


	if(inX)
	{
		if(std::abs(getY() - closestY) < radius)
		{
			//Change direction only if the ball is going towards the center of the rectangle
			if(std::signbit(getDir().y) == std::signbit(rect.y + (rect.h / 2) - getY()))
			{
				//Select angle
				static const float pi = 3.141592654f;
				if (std::signbit(getDir().y))
				{
					setDir(map(getX(), rect.x, rect.x + rect.w, 3*pi/4, pi/4));
				}
				else
				{
					setDir(-map(getX(), rect.x, rect.x + rect.w, 3*pi/4, pi/4));
				}
				//reverseDirY();
			}
			toReturn = true;
		}
	}
	if(inY)
	{
		if(std::abs(getX() - closestX) < radius)
		{
			//Change direction only if the ball is going towards the center of the rectangle
			if(std::signbit(getDir().x) == std::signbit(rect.x + (rect.w / 2) - getX()))
			{
				//Select angle
				static const float pi = 3.141592654f;
				if (std::signbit(getDir().x))
				{
					setDir(-map(getY(), rect.y, rect.y + rect.h, pi/4, -pi/4));
				}
				else
				{
					setDir(-map(getY(), rect.y, rect.y + rect.h, 3*pi/4, 5*pi/4));
				}
				//reverseDirX();
			}
			toReturn = true;
		}
	}

	return toReturn;
}