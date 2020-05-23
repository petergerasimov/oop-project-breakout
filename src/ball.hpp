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
		//maps variable x from range [a,b] to range [c,d]
		float map(float x, float a, float b, float c, float d);
	public:
		Ball();
		Ball(sf::RenderWindow* window);
		//Setters
		void setRadius(float radius);
		//Getters
		float getRadius();
		Circle getCircle();

		void reverseDirX();
		void reverseDirY();
		bool collRect(Rect rect);

};

#endif //__BALL_HPP