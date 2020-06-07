#ifndef __BRICK_HPP
#define __BRICK_HPP

#include "gameObject.hpp"

/**
* Клас за игрови обект - тухла.
*/
class Brick : public GameObject
{
	private:
		/**
		* Широчина на тухлата.
		*/
		float width = 50;
		/**
		* Височина на тухлата.
		*/
		float height = 10;
		/**
		* Форма на тухлата.
		*/
		sf::RectangleShape shape;
		/**
		* Метод, който рисува тухлата.
		*/
		void draw();
		/**
		* Метод, който инициализира тухлата.
		*/
		void init();
	public:
		/**
		* Инициализира тухлата ( вика init() ).
		*/
		Brick();
		/**
		* Инициализира тухлата ( вика init() ) и задава прозорец.
		* @param window указател към прозорец
		*/
		Brick(sf::RenderWindow* window);
		Brick& operator=(const Brick& b);
		//Setters
		void setWidth(float width);
		void setHeight(float height);
		//Getters
		float getWidth() const;
		float getHeight() const;
		Rect getRect();
};

#endif //__BRICK_HPP