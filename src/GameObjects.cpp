#include "GameObjects.h"

GameObjects::GameObjects(std::string fileName)
{

}
void GameObjects::showShape(sf::RenderWindow&)const
{

}
void GameObjects::setLocation(const int x, const int y)
{
	m_locations.push_back(sf::Vector2f(x, y));
}