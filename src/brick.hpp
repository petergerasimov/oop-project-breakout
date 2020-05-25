#ifndef __BRICK_HPP
#define __BRICK_HPP

#include "gameObject.hpp"

class Brick : public GameObject
{
	private:
		float width = 50;
		float height = 10;
		sf::RectangleShape shape;
		void draw();
		void init();
	public:
		Brick();
		Brick(sf::RenderWindow* window);
		Brick& operator=(const Brick& b);
		//Setters
		void setWidth(float width);
		void setHeight(float height);
		//Getters
		float getWidth() const;
		float getHeight() const;
		Rect getRect();
};

#endif //__BRICK_HPP