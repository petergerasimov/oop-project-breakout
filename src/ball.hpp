#ifndef __BALL_HPP
#define __BALL_HPP

#include "gameObject.hpp"
#include "gameUtils.hpp"

class Ball : public GameObject
{
	private:
		float radius = 5;
		sf::CircleShape shape;
		sf::Texture shapeTexture;
		void draw();
		void init();
	public:
		Ball();
		Ball(sf::RenderWindow* window);
		//Setters
		void setRadius(float radius);
		//Getters
		float getRadius();
		Circle getCircle();

		void update();
		void reverseDirX();
		void reverseDirY();

};

#endif //__BALL_HPP