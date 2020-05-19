#ifndef __COLLISIONS_HPP
#define __COLLISIONS_HPP

#include "gameUtils.hpp"


namespace colls
{
	bool circleCircle(Circle a, Circle b);
	bool circleRectangle(Circle circle, Rect rect);
}

#endif //__COLLISIONS_HPP