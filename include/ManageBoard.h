#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "BuildBoard.h"
//#include "macros.h"


class ManageBoard
{
public:
	ManageBoard();
	void runBoard();
	void getBoardSizeFromUser();
	void setMenuBar(sf::RenderWindow&);
	void printWindow(sf::RenderWindow&)const;


private:
	BuildBoard m_board;

};