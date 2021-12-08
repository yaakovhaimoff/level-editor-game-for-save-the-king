#include "ManageBoard.h"

//ManageBoard::ManageBoard()
//{
//
//}
//__________________________
void ManageBoard::runBoard()
{
	auto window = sf::RenderWindow(sf::VideoMode(900, 900), "Save the king");

	while (window.isOpen())
	{
		window.clear();
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
//___________________________________________________________
void ManageBoard::printWindow(sf::RenderWindow& window)const
{
	m_board.printDefaultBoard(window);
	m_board.printMenuBoard(window);
	//m_board.printObjectsBoard(window);
}