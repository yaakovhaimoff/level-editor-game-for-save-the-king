#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
	auto shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		window.clear();
		window.draw(shape);
		window.display();

		for (auto event = sf::Event{}; window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
}
