#include "ManageWindow.h"

//________________________
ManageWindow::ManageWindow()
{
	if (!this->readSavedBoard())
		this->getBoardSizeFromUser();
}
//______________________________________
void ManageWindow::getBoardSizeFromUser()
{
	int rows, cols;
	std::cout << "Welcome to Save The King!\n\n";
	std::cout << "In order to edit your level, Enter\n\n";
	std::cout << "the number of rows and cols you would like to have\n\n";
	std::cout << "in your board:\n\n";
	std::cin >> rows >> cols;
	m_board = ManageBoard(rows, cols);
}
//__________________________
void ManageWindow::runBoard()
{
	int buttonPressed, menuButton = DO_NOTHING;
	auto window = sf::RenderWindow(sf::VideoMode(882, 900), "SAVE THE KING");
	int row = 0;
	while (window.isOpen())
	{
		window.clear(BACKGROUND_COLOR);
		this->printWindow(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				// getting the location of where the mouse was pressed
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (m_board.handleClickInMenuBar(location, buttonPressed))
				{
					menuButton = buttonPressed;
				}
				this->checkButtonPressedOnMenu(window, menuButton, location);
				break;
			}
			case sf::Event::MouseMoved:
			{
				handleMouseMovement(menuButton, event, window);
				break;
			}
			}
		}
	}
}
//________________________________________________________________________________________________
void ManageWindow::handleMouseMovement(int menuButton, sf::Event& event, sf::RenderWindow& window)
{
	auto move = sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y);
	// checking if mouse movement is in board area
	if (m_board.handleClickOnBoard(move))
	{
		window.clear(BACKGROUND_COLOR);
		this->printWindow(window);
		// when moving an object
		if (!this->checkIfObjectIsOnBoard(DO_NOTHING, move))
		{
			this->printObjectMovement(menuButton, window, move);
		}
		// when pressed on erase, highlights the object which is pointed by the mouse
		else if (m_board.handleClickOnBoard(move) && this->checkIfObjectIsOnBoard(DO_NOTHING, move)
			&& menuButton == ERASE_BOARD_OBJECT)
		{
			auto deleteSignal = sf::RectangleShape({ 60, 60 });
			deleteSignal.setPosition(move);
			deleteSignal.setFillColor(sf::Color::Red);
			window.draw(deleteSignal);
		}
			window.display();
	}
}
//______________________________________________________________________________________________________
void ManageWindow::printObjectMovement(int menuButton, sf::RenderWindow& window, sf::Vector2f& location)
{
	switch (menuButton)
	{
	case KING_BOARD_OBJECT:
		m_king.showOneObject(window, location);
		break;

	case MAGE_BOARD_OBJECT:
		m_mage.showOneObject(window, location);
		break;

	case WARRIOR_BOARD_OBJECT:
		m_warrior.showOneObject(window, location);
		break;

	case THIEF_BOARD_OBJECT:
		m_thief.showOneObject(window, location);
		break;

	case WALL_BOARD_OBJECT:
		m_wall.showOneObject(window, location);
		break;

	case CROWN_BOARD_OBJECT:
		m_crown.showOneObject(window, location);
		break;

	case FIRE_BOARD_OBJECT:
		m_fire.showOneObject(window, location);
		break;

	case GATE_BOARD_OBJECT:
		m_gate.showOneObject(window, location);
		break;

	case GATE_KEY_BOARD_OBJECT:
		m_key.showOneObject(window, location);
		break;

	case MONSTER_BOARD_OBJECT:
		m_monster.showOneObject(window, location);
		break;

	case TELEPORT_BOARD_OBJECT:
		m_teleport.showOneObject(window, location);
		break;
	}
}
//___________________________________________________________________________________________________________
void ManageWindow::checkButtonPressedOnMenu(sf::RenderWindow& window, int menuButton, sf::Vector2f& location)
{
	switch (menuButton)
	{
	case NEW_BOARD_OBJECT:
		this->eraseBoard();
		/*window.clear(BACKGROUND_COLOR);
		this->printWindow(window);
		window.display();
		this->getBoardSizeFromUser();*/
		break;

	case SAVE_BOARD_OBJECT:
		this->saveBoard();
		break;

	case ERASE_BOARD_OBJECT:
		if (m_board.handleClickOnBoard(location))
			this->checkIfObjectIsOnBoard(ERASE_BOARD_OBJECT, location);
		break;

	default:
		this->addObject(menuButton, location);
		break;
	}
}
//_________________________________________________________________________
void ManageWindow::addObject(int menuObject, sf::Vector2f& locationPressed)
{
	if (m_board.handleClickOnBoard(locationPressed) && !this->checkIfObjectIsOnBoard(menuObject, locationPressed))
	{
		switch (menuObject)
		{
		case KING_BOARD_OBJECT:
			if (m_king.getAmountOfLocation() < PLAYER_EXIST)
				m_king.setLocation(locationPressed);
			break;

		case MAGE_BOARD_OBJECT:
			if (m_mage.getAmountOfLocation() < PLAYER_EXIST)
				m_mage.setLocation(locationPressed);
			break;

		case WARRIOR_BOARD_OBJECT:
			if (m_warrior.getAmountOfLocation() < PLAYER_EXIST)
				m_warrior.setLocation(locationPressed);
			break;

		case THIEF_BOARD_OBJECT:
			if (m_thief.getAmountOfLocation() < PLAYER_EXIST)
				m_thief.setLocation(locationPressed);
			break;

		case WALL_BOARD_OBJECT:
			m_wall.setLocation(locationPressed);
			break;

		case CROWN_BOARD_OBJECT:
			if (m_crown.getAmountOfLocation() < PLAYER_EXIST)
				m_crown.setLocation(locationPressed);
			break;

		case FIRE_BOARD_OBJECT:
			m_fire.setLocation(locationPressed);
			break;

		case GATE_BOARD_OBJECT:
			m_gate.setLocation(locationPressed);
			break;

		case GATE_KEY_BOARD_OBJECT:
			m_key.setLocation(locationPressed);
			break;

		case MONSTER_BOARD_OBJECT:
			m_monster.setLocation(locationPressed);
			break;

		case TELEPORT_BOARD_OBJECT:
			m_teleport.setLocation(locationPressed);
			break;

		default:
			break;
		}
	}
}
//___________________________________________________________________________________________
bool ManageWindow::checkIfObjectIsOnBoard(int menuButton, sf::Vector2f& buttonPressedOnBoard)
{
	// if found the location in one of the objects, will not continue checking the other objects
	if (m_king.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_mage.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_warrior.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_thief.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_wall.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_crown.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_fire.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_gate.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_key.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_monster.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;
	if (m_teleport.boardObjectExists(menuButton, buttonPressedOnBoard))
		return true;

	return false;
}
//______________________________
void ManageWindow::eraseBoard()
{
	m_king.eraseAllLocation();
	m_mage.eraseAllLocation();
	m_warrior.eraseAllLocation();
	m_thief.eraseAllLocation();
	m_wall.eraseAllLocation();
	m_crown.eraseAllLocation();
	m_fire.eraseAllLocation();
	m_gate.eraseAllLocation();
	m_key.eraseAllLocation();
	m_monster.eraseAllLocation();
	m_teleport.eraseAllLocation();
}
//__________________________________________________________
void ManageWindow::printWindow(sf::RenderWindow& window)const
{
	m_board.printDefaultBoard(window);
	m_board.printMenuBoard(window);
	this->printObjects(window);
}
//___________________________________________________________
void ManageWindow::printObjects(sf::RenderWindow& window)const
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
//_____________________________
void ManageWindow::saveBoard()
{
	std::ofstream file;
	file.open("Board.txt");
	std::vector<std::vector<char>> boardToSave;
	this->intializeVectorToSaveBoard(boardToSave);

	m_king.saveBoardObjectsToVector(boardToSave);
	m_mage.saveBoardObjectsToVector(boardToSave);
	m_warrior.saveBoardObjectsToVector(boardToSave);
	m_thief.saveBoardObjectsToVector(boardToSave);
	m_wall.saveBoardObjectsToVector(boardToSave);
	m_crown.saveBoardObjectsToVector(boardToSave);
	m_fire.saveBoardObjectsToVector(boardToSave);
	m_gate.saveBoardObjectsToVector(boardToSave);
	m_key.saveBoardObjectsToVector(boardToSave);
	m_monster.saveBoardObjectsToVector(boardToSave);
	m_teleport.saveBoardObjectsToVector(boardToSave);

	for (int i = 0; i < m_board.getBoardLength(); i++)
	{
		for (int j = 0; j < m_board.getBoardWidth(); j++)
		{
			file << boardToSave[i][j];
		}
		file << "\n";
	}
}
//________________________________________________________________________________________
void ManageWindow::intializeVectorToSaveBoard(std::vector<std::vector<char>>& boardToSave)
{
	int rows = m_board.getBoardLength();
	int cols = m_board.getBoardWidth();
	boardToSave.resize(rows, std::vector<char>(cols));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			boardToSave[i][j] = ' ';
		}
	}
}
//_________________________________
bool ManageWindow::readSavedBoard()
{
	std::ifstream savedFileBoard;
	savedFileBoard.open("Board.txt");
	if (!savedFileBoard.is_open())
		std::cout << "No baord saved previously\n\n";
	sf::Vector2f boardCharPosition;
	int row = 0, col = 0;
	bool isFile = false;
	while (savedFileBoard)
	{
		isFile = true;
		std::string boardLine;
		std::getline(savedFileBoard, boardLine);
		if (boardLine.size() > col)
			col = boardLine.size();
		for (int i = 0; i < boardLine.size(); i++)
		{
			int c = boardLine[i];
			boardCharPosition.x = (float)(SIDE_WIDTH + (CELL + SPACE) * i);
			boardCharPosition.y = (float)(SIDE_LENGTH + (CELL + SPACE) * row);
			this->addToBoardFromFile(c, boardCharPosition);
		}
		row++;
	}
	m_board = ManageBoard(row, col);
	return isFile;
}
//_________________________________________________________________
void ManageWindow::addToBoardFromFile(int c, sf::Vector2f location)
{
	switch (c)
	{
	case KING:
		m_king.setLocation(location);
		break;

	case MAGE:
		m_mage.setLocation(location);
		break;

	case WARRIOR:
		m_warrior.setLocation(location);
		break;

	case THIEF:
		m_thief.setLocation(location);
		break;

	case GATE_KEY:
		m_key.setLocation(location);
		break;

	case FIRE:
		m_fire.setLocation(location);
		break;

	case TELEPORT:
		m_teleport.setLocation(location);
		break;

	case CROWN:
		m_crown.setLocation(location);
		break;

	case MONSTER:
		m_monster.setLocation(location);
		break;

	case GATE:
		m_gate.setLocation(location);
		break;

	case WALL:
		m_wall.setLocation(location);
		break;
	}
}