#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include "gameObject.hpp"

class Paddle : public GameObject
{
	private:
		float width = 50;
		float height = 10;
		sf::RectangleShape shape;
		sf::Texture shapeTexture;
		sf::RenderWindow* window = nullptr;
		void draw();
		void input();
	public:
		Paddle();
		Paddle(sf::RenderWindow* window);
		void update();

		//Setters
		void setWidth(float width);
		void setHeight(float height);
		//Getters
		float getWidth();
		float getHeight();

};

#endif //__PADDLE_HPP