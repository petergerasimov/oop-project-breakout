#ifndef __GAME_HPP
#define __GAME_HPP

class Game
{
	private:
		sf::CircleShape shape;
		sf::Texture shapeTexture;
		sf::RenderWindow* window;
	public:
		Game(sf::RenderWindow* window);
		void update();
};

#endif //__GAME_HPP