#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "BuildBoard.h"

class ManageBoard
{
public:
	ManageBoard();
	void runBoard();
	void getBoardSizeFromUser();
	void printWindow(sf::RenderWindow&)const;


private:
	BuildBoard m_board;

};