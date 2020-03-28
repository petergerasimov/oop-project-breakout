#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include "gameUtils.hpp"

class GameObject
{
	private:
		Point pos = {0, 0};
		Vector2D dir = {0, 0};
		float vel = 1;
		sf::RenderWindow* window = nullptr;
		draw();
	public:
		GameObject();
		~GameObject();
		//Setters
		void setX(float x);
		void setY(float y);
		void setPos(Point p);
		void setDir(Vector2D dir);
		//Getters
		float getX();
		float getY();
		Point getPos();
		Vector2D getDir();

		void update();
};


#endif //__GAME_OBJECT_HPP