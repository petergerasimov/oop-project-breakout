#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include "gameUtils.hpp"

class GameObject
{
	private:
		sf::Vector2f pos = {0, 0};
		sf::Vector2f dir = {0, 0};
		sf::Texture shapeTexture;
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
		void setTexture(std::string filename);

		//Getters
		float getX() const;
		float getY() const;
		sf::Vector2f getPos() const;
		float getVelocity() const;
		sf::RenderWindow* getWindow() const;
		Rect getBoundingBox() const;
		sf::Vector2f getDir() const;
		sf::Texture* getTexture();

		virtual void draw();
		virtual void updatePos();
		virtual void checkBounds();
		void update();
};


#endif //__GAME_OBJECT_HPP