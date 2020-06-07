#ifndef __BALL_HPP
#define __BALL_HPP

#include "gameObject.hpp"
#include "gameUtils.hpp"

/**
* Клас за игрови обект - топка.
*/
class Ball : public GameObject
{
	private:
		/**
		* Радиус на топката.
		*/
		float radius = 5;
		/**
		* Форма на топката.
		*/
		sf::CircleShape shape;

		/**
		* Метод, който рисува топката.
		*/
		void draw();
		/**
		* Метод, който проверява дали топката е в ограниченията.
		*/
		void checkBounds();
		/**
		* Метод, който инициализира топката.
		*/
		void init();
		/**
		* Mетод, който връща изображението на x от множество [a,b] в множество [c,d].
		* @param x реално число
		* @param a реално число
		* @param b реално число
		* @param c реално число
		* @param d реално число
		* @return реално число
		*/
		float map(float x, float a, float b, float c, float d);
	public:
		/**
		* Инициализира топката ( вика init() ).
		*/
		Ball();
		/**
		* Инициализира топката ( вика init() ) и задава прозорец.
		* @param window указател към прозорец
		*/
		Ball(sf::RenderWindow* window);
		//Setters
		/**
		* Задава радиуса на топката.
		* @param radius реално число
		*/
		void setRadius(float radius);
		//Getters
		/**
		* Връща радиуса.
		* @return реално число
		*/
		float getRadius();
		/**
		* Връща радиуса и координатите като окръжност.
		* @return окръжност (Circle)
		*/
		Circle getCircle();

		/**
		* Обръща посоката по x.
		*/
		void reverseDirX();
		/**
		* Обръща посоката по y.
		*/
		void reverseDirY();
		/**
		* Проверява колизиите между топката и правоъгълник.
		* @param rect правоъгълник
		* @return ако е осъществена колизия - истина.
		*/
		bool collRect(Rect rect);

};

#endif //__BALL_HPP