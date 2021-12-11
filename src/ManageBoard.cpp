#include "ManageBoard.h"

//______________________________________________________________
ManageBoard::ManageBoard(int length, int width) : m_length(length),
m_width(width)
{}
//___________________________________
int ManageBoard::getBoardLength()const
{
	return m_length;
}
//___________________________________
int ManageBoard::getBoardWidth()const
{
	return m_width;
}
// printing the board layout, and the objects background
//________________________________________________________________
void ManageBoard::printDefaultBoard(sf::RenderWindow& window) const
{
	auto backGroungRect = sf::RectangleShape({ (float)63.3 * m_length, (float)63.3 * m_width });
	backGroungRect.setFillColor(sf::Color::Black);
	backGroungRect.setPosition(sf::Vector2f((float)(SIDE_WIDTH-3), (float)(SIDE_LENGTH-3)));
	window.draw(backGroungRect);

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
void ManageBoard::printMenuBoard(sf::RenderWindow& window) const
{
	auto backGroungRect = sf::RectangleShape({ (float)63.5* MenuBar, (float)66 });
	backGroungRect.setFillColor(sf::Color::Black);
	window.draw(backGroungRect);

	auto menuButton = sf::RectangleShape({ 60, 60 });
	menuButton.setFillColor(MENU_COLOR);

	for (int row = 0; row < MenuBar; row++)
	{
		menuButton.setPosition(sf::Vector2f((float)((CELL + SPACE) * row) +1, (float)SPACE));
		window.draw(menuButton);
	}
}
// deciding if the menu bar was pressed on, and if yes which one
//____________________________________________________________________________________________
bool ManageBoard::handleClickInMenuBar(const sf::Vector2f& buttonPressedOnBoard, int& location)
{
	sf::RectangleShape menuBar({ 60, 60 });
	for (int row = 0; row < MenuBar; row++)
	{
		menuBar.setPosition(sf::Vector2f((float)(CELL + SPACE) * row, (float)SPACE));

		if (menuBar.getGlobalBounds().contains(buttonPressedOnBoard))
		{
			location = row;
			return true;
		}
	}
	location = DO_NOTHING;
	return false;
}
// checking if the user click was in the board area
//_____________________________________________________________________
bool ManageBoard::handleClickOnBoard(sf::Vector2f& buttonPressedOnBoard)
{
	sf::RectangleShape board({ 60, 60 });
	for (int row = 0; row < m_length; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			board.setPosition(sf::Vector2f((float)(SIDE_WIDTH + (CELL + SPACE) * col),
				(float)(SIDE_LENGTH + (CELL + SPACE) * row)));
			if (board.getGlobalBounds().contains(buttonPressedOnBoard))
			{
				buttonPressedOnBoard = sf::Vector2f((float)(SIDE_WIDTH + (CELL + SPACE) * col),
					(float)(SIDE_LENGTH + (CELL + SPACE) * row));
				return true;
			}
		}
	}
	return false;
}
