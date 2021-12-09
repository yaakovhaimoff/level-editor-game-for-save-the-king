#include "GameObjects.h"

GameObjects::GameObjects(std::string fileName, int x, int y, char key)
	: m_key(key)
{
	m_locations.push_back(sf::Vector2f(x, y));
	m_textureFile.loadFromFile(fileName);
}
void GameObjects::showShape(sf::RenderWindow& window)const
{
	sf::Sprite sprite;

	for (int row = 0; row < m_locations.size(); row++)
	{
		
		sprite.setPosition(m_locations[row]);
		sprite.setTexture(m_textureFile);
		window.draw(sprite);
	}
}
void GameObjects::setLocation(const int x, const int y)
{
	m_locations.push_back(sf::Vector2f(x, y));
}