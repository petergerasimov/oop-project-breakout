#include "collisions.hpp"

bool colls::circleCircle(Circle a, Circle b)
{
	return (std::hypotf(b.x - a.x, b.y - a.y) < (a.r + b.r));
}

bool colls::circleRectangle(Circle circle, Rect rect)
{
	sf::Vector2f temp = {circle.x, circle.y};
	//Got the concept from - http://www.jeffreythompson.org/collision-detection/circle-rect.php
	//Check left and right edges of the rectangle
	if (circle.x < rect.x)
		temp.x = rect.x;
	else if (circle.x > rect.x + rect.w)
		temp.x = rect.x + rect.w;
	//Check top and bottom edges of the rectangle
	if (circle.y < rect.y)
		temp.y = rect.y;
	else if (circle.y > rect.y + rect.h)
		temp.y = rect.y + rect.h;

	//return std::hypotf(circle.x - temp.x, circle.y - temp.y) <= circle.r;
	return (circle.x - temp.x) * (circle.x - temp.x) + (circle.y - temp.y) * (circle.y - temp.y) <= circle.r * circle.r;
}