#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"

class BuildBoard
{
public:
	BuildBoard();
	BuildBoard(int, int);
	void printDefaultBoard(sf::RenderWindow&) const;
	void printObjectsBoard(sf::RenderWindow&) const;
	void printMenuBoard(sf::RenderWindow&) const;

private:
	int m_length;
	int m_width;
};