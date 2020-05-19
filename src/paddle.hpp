#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include "gameObject.hpp"
#include "gameUtils.hpp"

class Paddle : public GameObject
{
	private:
		float width = 50;
		float height = 10;
		sf::RectangleShape shape;
		sf::Texture shapeTexture;
		void draw();
		void input();
		void init();
		void updatePos();
	public:
		Paddle();
		Paddle(sf::RenderWindow* window);


		//Setters
		void setWidth(float width);
		void setHeight(float height);
		//Getters
		float getWidth();
		float getHeight();
		Rect getRect();

};

#endif //__PADDLE_HPP