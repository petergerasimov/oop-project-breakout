#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include "gameObject.hpp"
#include "gameUtils.hpp"

/**
* Клас за игрови обект - хилка.
*/
class Paddle : public GameObject
{
	private:
		/**
		* Широчина на хилката.
		*/
		float width = 50;
		/**
		* Височина на хилката.
		*/
		float height = 10;
		/**
		* Форма на хилката.
		*/
		sf::RectangleShape shape;
		/**
		* Метод, който рисува хилката.
		*/
		void draw();
		/**
		* Метод, който приема вход от клавиатурата.
		*/
		void input();
		/**
		* Метод, който проверява дали хилката е в ограниченията.
		*/
		void checkBounds();
		/**
		* Метод, който инициализира хилката.
		*/
		void init();
		/**
		* Метод, който обновява позицията на хилката спрямо входа от клавиатурата.
		*/
		void updatePos();
	public:
		/**
		* Инициализира хилката ( вика init() ).
		*/
		Paddle();
		/**
		* Инициализира хилката ( вика init() ) и задава прозорец.
		* @param window указател към прозорец
		*/
		Paddle(sf::RenderWindow* window);


		//Setters
		/**
		* Задава широчина на хилката.
		* @param width реално число
		*/
		void setWidth(float width);
		/**
		* Задава височина на хилката.
		* @param height реално число
		*/
		void setHeight(float height);
		//Getters
		/**
		* Връща широчината на хилката.
		* @return реално число
		*/
		float getWidth();
		/**
		* Връща височината на хилката.
		* @return реално число
		*/
		float getHeight();
		/**
		* Връща височина, широчина, и координати като правоъгълник.
		* @return правоъгълник (Rect)
		*/
		Rect getRect();

};

#endif //__PADDLE_HPP