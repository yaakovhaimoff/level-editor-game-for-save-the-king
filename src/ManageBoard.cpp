#include "ManageBoard.h"

//________________________
ManageBoard::ManageBoard()
{
	this->getBoardSizeFromUser();
}
//__________________________
void ManageBoard::runBoard()
{
	auto window = sf::RenderWindow(sf::VideoMode(1100, 1100), "Save the king");

	while (window.isOpen())
	{
		window.clear(BACKGROUND_COLOR);
		this->printWindow(window);
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
//______________________________________
void ManageBoard::getBoardSizeFromUser()
{
	int rows, cols;
	std::cout << "Enter the size for the borad,\n";
	std::cout << "rows and cols\n";
	std::cin >> rows >> cols;
	m_board = BuildBoard(rows, cols);
}
//__________________________________________________________
void ManageBoard::printWindow(sf::RenderWindow& window)const
{
	m_board.printDefaultBoard(window);
	m_board.printMenuBoard(window);
	this->printObjects(window);
}
//___________________________________________________________
void ManageBoard::printObjects(sf::RenderWindow& window)const
{
	m_king.showShape(window);
	m_mage.showShape(window);
	m_warrior.showShape(window);
	m_thief.showShape(window);
	m_wall.showShape(window);
	m_crown.showShape(window);
	m_fire.showShape(window);
	m_gate.showShape(window);
	m_key.showShape(window);
	m_monster.showShape(window);
	m_teleport.showShape(window);
	m_erase.showShape(window);
	m_newBoard.showShape(window);
	m_saveBoard.showShape(window);
}