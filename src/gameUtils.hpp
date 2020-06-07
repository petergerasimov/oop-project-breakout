#ifndef __GAME_UTILS_HPP
#define __GAME_UTILS_HPP

/**
* Структура за кръг.
*/
struct Circle : public sf::Vector2f
{
	/**
	* Радиус на кръга.
	*/
	float r;
	/**
	* Конструктор.
	* @param x абсциса
	* @param y ордината
	* @param r радиус
	*/
	Circle(float x, float y, float r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
};
/**
* Структура за правоъгълник.
*/
struct Rect : public sf::Vector2f
{
	/**
	* Широчина на правоъгълника.
	*/
	float w;
	/**
	* Височина на правоъгълника.
	*/
	float h;
	/**
	* Конструктор.
	* @param x абсциса
	* @param y ордината
	* @param w широчина
	* @param h височина
	*/
	Rect(float x, float y, float w, float h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

#endif //__GAME_UTILS_HPP