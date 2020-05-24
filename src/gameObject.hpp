#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include "gameUtils.hpp"

class GameObject
{
	private:
		sf::Vector2f pos = {0, 0};
		sf::Vector2f dir = {0, 0};
		float vel = 1;
		sf::RenderWindow* window = nullptr;
		Rect boundingBox = {0, 0, 0, 0};

	public:
		GameObject();
		GameObject(sf::RenderWindow* window);
		~GameObject();

		//Setters
		void setX(float x);
		void setY(float y);
		void setPos(sf::Vector2f p);
		void setDir(sf::Vector2f dir);
		void setDir(float angle);
		void setVelocity(float vel);
		void setWindow(sf::RenderWindow* window);
		void setBoundingBox(Rect boundingBox);

		//Getters
		float getX();
		float getY();
		sf::Vector2f getPos();
		float getVelocity();
		sf::RenderWindow* getWindow();
		Rect getBoundingBox();

		sf::Vector2f getDir();
		virtual void draw();
		virtual void updatePos();
		virtual void checkBounds();
		void update();
};


#endif //__GAME_OBJECT_HPP