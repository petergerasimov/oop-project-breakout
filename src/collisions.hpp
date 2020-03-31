#ifndef __COLLISIONS_HPP
#define __COLLISIONS_HPP

#include "gameUtils.hpp"


namespace colls
{
	//Add a circle and rectangle struct
	bool circleCircle(Circle a, Circle b);
	bool circleRectangle(Circle circle, Rect rect);
}

#endif //__COLLISIONS_HPP