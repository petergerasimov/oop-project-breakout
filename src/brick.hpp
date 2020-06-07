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
		/**
		* Предефинирана операция за присвояване.
		*/
		Brick& operator=(const Brick& b);
		//Setters
		/**
		* Задава широчината на тухлата.
		* @param width реално число
		*/
		void setWidth(float width);
		/**
		* Задава височина на тухлата.
		* @param height реално число
		*/
		void setHeight(float height);
		//Getters
		/**
		* Връща широчината на тухлата.
		* @return реално число
		*/
		float getWidth() const;
		/**
		* Връща височината на тухлата.
		* @return реално число
		*/
		float getHeight() const;
		/**
		* Връща широчината, височината и координатите.
		* @return правоъгълник (Rect)
		*/
		Rect getRect();
};

#endif //__BRICK_HPP