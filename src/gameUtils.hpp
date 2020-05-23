#ifndef __GAME_UTILS_HPP
#define __GAME_UTILS_HPP

struct Circle : public sf::Vector2f{
	float r;
	Circle(float x, float y, float r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

struct Rect : public sf::Vector2f{
	float w;
	float h;
	Rect(float x, float y, float w, float h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

#endif //__GAME_UTILS_HPP