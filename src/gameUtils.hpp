#ifndef __GAME_UTILS_HPP
#define __GAME_UTILS_HPP

struct Point
{
	float x;
	float y;
};

struct Vector2D : Point{};

struct Circle : Point{float r;};

struct Rect : Point{float w; float h;};

#endif //__GAME_UTILS_HPP