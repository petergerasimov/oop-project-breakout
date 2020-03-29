#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include "gameUtils.hpp"

class GameObject
{
	private:
		Point pos = {0, 0};
		Vector2D dir = {0, 0}; //Use sfml vector instead of this
		float vel = 1;
		sf::RenderWindow* window = nullptr;

	public:
		GameObject();
		GameObject(sf::RenderWindow* window);
		~GameObject();

		//Setters
		void setX(float x);
		void setY(float y);
		void setPos(Point p);
		void setDir(Vector2D dir);
		void setVelocity(float vel);

		//Getters
		float getX();
		float getY();
		Point getPos();
		float getVelocity();

		Vector2D getDir();
		void updatePos();
		void update();
};


#endif //__GAME_OBJECT_HPP