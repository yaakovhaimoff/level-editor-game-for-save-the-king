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
void GameObjects::setLocation(sf::Vector2f& location)
{
	m_locations.push_back(location);
}
int GameObjects::getAmountOfLocation()const
{
	return m_locations.size();
}
bool GameObjects::boardObjectExists(sf::Vector2f& buttonPressedOnBoard)
{
	for (int row = 1; row < m_locations.size(); row++)
		if (m_locations[row] == buttonPressedOnBoard)
			return true;

	return false;
}