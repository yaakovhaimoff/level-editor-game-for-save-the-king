#include "BuildBoard.h"

//______________________________________________________________
BuildBoard::BuildBoard(int length, int width): m_length(length),
m_width(width)
{}
//________________________________________________________________
void BuildBoard::printDefaultBoard(sf::RenderWindow& window) const
{
	auto objectShape = sf::RectangleShape({ 60, 60 });
	objectShape.setFillColor(BOARD_COLOR);

	for (int row = 0; row < m_length; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			objectShape.setPosition(sf::Vector2f((float)(SIDE_WIDTH + (CELL + SPACE) * col),
				(float)(SIDE_LENGTH + (CELL + SPACE) * row)));
			window.draw(objectShape);
		}
	}
}
//_____________________________________________________________
void BuildBoard::printMenuBoard(sf::RenderWindow& window) const
{
	auto menuButton = sf::RectangleShape({ 60, 60 });
	menuButton.setFillColor(MENU_COLOR);

	for(int row = 0; row < MenuBar; row++)
	{
		menuButton.setPosition(sf::Vector2f((float)(SIDE_WIDTH + (CELL + SPACE) * row), (float)(SPACE)));
		window.draw(menuButton);
	}
}
//_________________________________________________________
void BuildBoard::printObjectsBoard(sf::RenderWindow&) const
{
	 
}