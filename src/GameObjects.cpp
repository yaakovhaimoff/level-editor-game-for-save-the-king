#include "GameObjects.h"

//____________________________________________________________________
GameObjects::GameObjects(std::string fileName, int x, int y, char key)
	: m_key(key)
{
	m_locations.push_back(sf::Vector2f(x, y));
	m_textureFile.loadFromFile(fileName);
}
//________________________________________________________
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
//_______________________________________________________________________________
void GameObjects::showOneObject(sf::RenderWindow& window, sf::Vector2f& location)
{
	sf::Sprite sprite;
	sprite.setPosition(location);
	sprite.setTexture(m_textureFile);
	window.draw(sprite);
}
//___________________________________________________
void GameObjects::setLocation(sf::Vector2f& location)
{
	m_locations.push_back(location);
}
int GameObjects::getAmountOfLocation()const
{
	return m_locations.size();
}
//_____________________________________________________________________
bool GameObjects::boardObjectExists(int menuButton, sf::Vector2f& buttonPressedOnBoard)
{
	for (int row = 0; row < m_locations.size(); row++)
	{
		if (m_locations[row] == buttonPressedOnBoard)
		{
			// if in erase menu bar case, will erase this location
			if (menuButton == ERASE_BOARD_OBJECT)
				m_locations.erase(m_locations.begin() + row);

			return true;
		}
	}
	return false;
}
//__________________________________
void GameObjects::eraseAllLocation()
{
	// saving the menu bar location 
	sf::Vector2f temp = m_locations[0];
	m_locations.clear();
	// restoring the menu bar location
	m_locations.push_back(temp);
}
//__________________________________________________________
void GameObjects::eraseLocation(sf::Vector2f& objectOnBoard)
{
	for (int row = 1; row < m_locations.size(); row++)
		if (m_locations[row] == objectOnBoard)
		{
			m_locations.erase(m_locations.begin() + row);
			break;
		}
}
//______________________________________________________________________________________
void GameObjects::saveBoardObjectsToVector(std::vector<std::vector<char>>& vectorToSave)
{
	int i, j;
	for (int row = 1; row < m_locations.size(); row++)
	{
		i = (m_locations[row].y - SIDE_WIDTH) / (CELL + SPACE);
		j = (m_locations[row].x - SIDE_LENGTH) / (CELL + SPACE);
		vectorToSave[i][j] = m_key;
	}
}

//objectShape.setPosition(sf::Vector2f(SIDE_WIDTH + (CELL + SPACE) * col,
//	SIDE_LENGTH + (CELL + SPACE) * row));