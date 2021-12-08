#include "ManageBoard.h"

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
		//this->setMenuBar();
		this->printWindow(window);
		this->setMenuBar(window);
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
void ManageBoard::setMenuBar(sf::RenderWindow& window)
{
	//C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs
	const char* FILES_NAMES[] = { "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\king.png", "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\mage.png",
		"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\warrior.png", "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\thief.png",
		"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\crown.png",
							"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\gate.png", "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\fire.png",
		"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\key.png", "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\monster.png",
		"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\teleport.png",
							"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\brickWall.png", "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\eraser.png",
		"C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\newBoard.png", "C:\\Users\\hyaak\\OneDrive\\School\\oop1\\ex4\\rcs\\saveBoard.png" };

	sf::Texture menuButton;
	sf::Sprite sprite;
	
	for (int row = 0; row < MenuBar; row++)
	{
		if (!menuButton.loadFromFile(FILES_NAMES[row]));
		sprite.setPosition(sf::Vector2f((float)(SIDE_WIDTH + (CELL + SPACE) * row), (float)(SPACE)));
		sprite.setTexture(menuButton);
		window.draw(sprite);
	}
}
