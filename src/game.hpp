#ifndef __GAME_HPP
#define __GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <vector>

/**
* Клас в който се реализира играта.
*/
class Game
{
	private:
		//SFML vars
		/**
		* Указател към прозореца върху който се рисуват обектите.
		*/
		sf::RenderWindow* window;
		/**
		* Указател към обекта за събития.
		*/
		sf::Event* event;
		/**
		* Шрифт за текст.
		*/
		sf::Font font;
		/**
		* Текст за резултата.
		*/
		sf::Text scoreText;
		/**
		* Текст за край на играта.
		*/
		sf::Text gameOverText;
		/**
		* Текст за име на играча.
		*/
		sf::Text playerNameText;
		/**
		* Обект от тип sf::Clock за измерване на време.
		*/
		sf::Clock clock;
		//window size vars
		/**
		* Широчина на прозореца.
		*/
		float width;
		/**
		* Височина на прозореца.
		*/
		float height;
		//Game objects
		/**
		* Обект от тип топка.
		*/
		Ball ball;
		/**
		* Обект от тип хилка.
		*/
		Paddle paddle;
		/**
		* Масив от тухли.
		*/
		std::vector<Brick> bricks;
		//Game vars
		/**
		* Променлива за резутат.
		*/
		int score = 0;
		/**
		* Име на играча.
		*/
		std::string playerName;
		/**
		* Променлива за най-високия резултат до момента.
		*/
		int highScore = 0;
		/**
		* Име на играча който държи рекорда.
		*/
		std::string hsHolder;
		/**
		* Животи на играча.
		*/
		int lives = 3;
		/**
		* Начална скорост.
		*/
		float initVelocity = 0.1;
		/**
		* Начална позиция на топката.
		*/
		sf::Vector2f ballStartPos;
		/**
		* Глобална скорост. Скоростта на всички обекти в играта.
		*/
		float gVelocity;

		/**
		* Метод за намиране на центъра на екрана.
		* @return центъра на екрана като sf::Vector2f
		*/
		sf::Vector2f getScreenCenter();
		/**
		* Метод, който връща колко време е изминало от предишното викане на този метод.
		* @return реално число, секунди
		*/
		float getDeltaTime();
		/**
		* Метод, който обновява скоростите.
		* Обновява ги спрямо изминалото време между кадрите,
		* за да може скоростта да е еднаква независимо от бързодействието.
		*/
		void updateVelocities();
		/**
		* Метод за въвеждане на тескт от клавиатурата.
		* @return въведен текскт
		*/
		std::string enterText();
		/**
		* Запазва най-високия резултат и името на човека, който го е направил.
		*/
		void saveHighScore(const char *file);
		/**
		* Зарежда последния най-висок резултат и името на човека, който го е направил.
		*/
		void loadHighScore(const char *file);
	public:
		/**
		* Конструктор. Задава указател към прозореца, на който ще бъдат представени обектите.
		* Указател към обект за събития и инициализира променливите на играта.
		* @param window указател към прозорец
		* @param event указател към обект за събития
		*/
		Game(sf::RenderWindow* window, sf::Event* event);
		/**
		* Сцена за главната игра.
		*/
		void gameScene();
		/**
		* Метод, който се извиква при изпускане на топчето.
		*/
		void onDeath();
		/**
		* Метод, който обновява резулатите.
		*/
		void scoreUpdate();
		/**
		* Сцена за край на играта.
		*/
		void gameOverScene();
		/**
		* Метод за инициализиране на игровите променливи.
		*/
		void setup();
		/**
		* Метод за обновяване. Тук е същинската логика на играта.
		*/
		void update();

};

#endif //__GAME_HPP