#include "Platform/PlatformHelper.hpp"
#include "game.hpp"

int main()
{
	PlatformHelper platform;

// #if defined(_DEBUG)
// 	std::cout << "Hello World!" << std::endl;
// #endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(600.0f * screenScalingFactor, 800.0f * screenScalingFactor), "Breakout!");
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	Game g(&window, &event);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		g.update();
		window.display();
	}

	return 0;
}
