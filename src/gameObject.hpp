#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include "gameUtils.hpp"
/**
* Клас за игрови обекти. Той е предназначен да бъде наследяван.
* Грижи се за позициите на обектите и за тяхното рисуване.
*/
class GameObject
{
	private:
		/**
 		* Позиция на обекта.
 		*/
		sf::Vector2f pos = {0, 0};
		/**
 		* Посоката в която обекта се движи.
 		*/
		sf::Vector2f dir = {0, 0};
		/**
 		* Текстура на обекта.
 		*/
		sf::Texture shapeTexture;
		/**
 		* Скорост на обекта.
 		*/
		float vel = 1;
		/**
 		* Указател към прозорецът върху който обекта ще бъде нарисуван.
 		*/
		sf::RenderWindow* window = nullptr;
		/**
 		* Ограничения извън които обекта не може да излиза.
 		*/
		Rect boundingBox = {0, 0, 0, 0};

	public:
		GameObject();
		/**
 		* Конструктор който задава прозореца върху който обекта да бъде нарисуван.
 		*/
		GameObject(sf::RenderWindow* window);
		~GameObject();

		//Setters
		/**
 		* Задава стойност на x.
		* @param x абсциса - реално число
 		*/
		void setX(float x);
		/**
 		* Задава стойност на y.
		* @param y ордината - реално число
 		*/
		void setY(float y);
		/**
 		* Задава позицията.
		* @param p позиция представена чрез sf::Vector2f
 		*/
		void setPos(sf::Vector2f p);
		/**
 		* Задава посоката.
		* @param dir посока представена чрез sf::Vector2f
 		*/
		void setDir(sf::Vector2f dir);
		/**
 		* Задава посоката.
		* @param angle посока представена чрез ъгъл
 		*/
		void setDir(float angle);
		/**
 		* Задава скоростта.
		* @param vel скорост - реално число
 		*/
		void setVelocity(float vel);
		/**
 		* Задава прозорец.
		* @param window указател към прозорец
 		*/
		void setWindow(sf::RenderWindow* window);
		/**
 		* Задава ограничения.
		* @param boundingBox правоъгълник
 		*/
		void setBoundingBox(Rect boundingBox);
		/**
 		* Задава текстура.
		* @param filename път на файл
 		*/
		void setTexture(std::string filename);

		//Getters
		/**
 		* Връща стойността на абсцисата
		* @return реално число
 		*/
		float getX() const;
		/**
 		* Връща стойността на ординатата
		* @return реално число
 		*/
		float getY() const;
		/**
 		* Връща позицията.
		* @return вектор (sf::Vector2f)
 		*/
		sf::Vector2f getPos() const;
		/**
 		* Връща скоростта.
		* @return реално число
 		*/
		float getVelocity() const;
		/**
 		* Връща указател към прозореца.
		* @return указател (sf::RenderWindow*)
 		*/
		sf::RenderWindow* getWindow() const;
		/**
 		* Връща ограниченията.
		* @return правоъгълник (Rect)
 		*/
		Rect getBoundingBox() const;
		/**
 		* Връща посоката.
		* @return вектор (sf::Vector2f)
 		*/
		sf::Vector2f getDir() const;
		/**
 		* Връща указател към текстурата.
		* @return указател (sf::Texture*)
 		*/
		sf::Texture* getTexture();

		/**
 		* Виртуален метод, който рисува обекта.
 		*/
		virtual void draw();
		/**
 		* Виртуален метод, който обновява позицията на обекта.
 		*/
		virtual void updatePos();
		/**
 		* Виртуален метод, който проверява дали обекта е в ограниченията си.
 		*/
		virtual void checkBounds();
		/**
 		* Обновява обекта. Вика виртуалните методи за рисуване, обновяване на позицията и проверка за ограниченията.
 		*/
		void update();
};


#endif //__GAME_OBJECT_HPP