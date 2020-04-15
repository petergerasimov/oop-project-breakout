#ifndef __COLLISIONS_HPP
#define __COLLISIONS_HPP

#include "gameUtils.hpp"


namespace colls
{
	// struct edge
	// {
	// 	bool vertical;
	// 	bool horizontal;
	// }
	bool circleCircle(Circle a, Circle b);
	bool circleRectangle(Circle circle, Rect rect);
}

#endif //__COLLISIONS_HPP