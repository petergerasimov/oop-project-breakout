#ifndef __BALL_HPP
#define __BALL_HPP

#include "gameObject.hpp"

class Ball : public GameObject
{
	private:
		float radius = 5;
		sf::CircleShape shape;
		sf::Texture shapeTexture;
		sf::RenderWindow* window = nullptr;
		void draw();
	public:
		Ball();
		Ball(sf::RenderWindow* window);
		//Setters
		void setRadius(float radius);
		//Getters
		float getRadius();
		void update();

};

#endif //__BALL_HPP