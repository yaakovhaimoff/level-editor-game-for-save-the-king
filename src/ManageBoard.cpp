#include "ManageBoard.h"

//______________________________________________________________
ManageBoard::ManageBoard(int length, int width) : m_length(length),
m_width(width)
{}
//________________________________________________________________
void ManageBoard::printDefaultBoard(sf::RenderWindow& window) const
{
	auto objectShape = sf::RectangleShape({ 60, 60 });
	objectShape.setFillColor(BOARD_COLOR);

	for (int row = 0; row < m_length; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			objectShape.setPosition(sf::Vector2f(SIDE_WIDTH + (CELL + SPACE) * col,
				SIDE_LENGTH + (CELL + SPACE) * row));
			window.draw(objectShape);
		}
	}
}
//_____________________________________________________________
void ManageBoard::printMenuBoard(sf::RenderWindow& window) const
{
	auto menuButton = sf::RectangleShape({ 60, 60 });
	menuButton.setFillColor(MENU_COLOR);

	for (int row = 0; row < MenuBar; row++)
	{
		menuButton.setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE));
		window.draw(menuButton);
	}
}
//____________________________________________________________________________________________
bool ManageBoard::handleClickInMenuBar(const sf::Vector2f& buttonPressedOnBoard, int& location)
{
	sf::RectangleShape menuBar({60, 60});
	for (int row = 0; row < MenuBar; row++)
	{
		menuBar.setPosition(sf::Vector2f((CELL + SPACE) * row, SPACE));
		
		if (menuBar.getGlobalBounds().contains(buttonPressedOnBoard))
		{
			location = row;
			return true;
		}
	}
	location = DO_NOTHING;
	return false;
}

//_____________________________________________________________________
bool ManageBoard::handleClickOnBoard(sf::Vector2f& buttonPressedOnBoard)
{
	sf::RectangleShape board({ 60, 60 });
	for (int row = 0; row < m_length; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			board.setPosition(sf::Vector2f(SIDE_WIDTH + (CELL + SPACE) * col,
				SIDE_LENGTH + (CELL + SPACE) * row));
			if (board.getGlobalBounds().contains(buttonPressedOnBoard))
			{
				buttonPressedOnBoard = sf::Vector2f(SIDE_WIDTH + (CELL + SPACE) * col,
					SIDE_LENGTH + (CELL + SPACE) * row);
				return true;
			}
		}
	}
	return false;
}
