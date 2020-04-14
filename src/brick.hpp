#ifndef __BRICK_HPP_
#define __BRICK_HPP_

#include "gameObject.hpp"

class Brick : public GameObject
{
	private:
		float width = 50;
		float height = 10;
		sf::RectangleShape shape;
		sf::Texture shapeTexture;
		void draw();
		void init();
	public:
		Brick();
		Brick(sf::RenderWindow* window);
		void update();

		//Setters
		void setWidth(float width);
		void setHeight(float height);
		//Getters
		float getWidth();
		float getHeight();
		Rect getRect();
};

#endif //__BRICK_HPP_