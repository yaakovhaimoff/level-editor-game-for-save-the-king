#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"

class BuildBoard
{
public:
	BuildBoard() = default;
	BuildBoard(int, int);
	void printDefaultBoard(sf::RenderWindow&) const;
	void printMenuBoard(sf::RenderWindow&) const;
	bool handleClickInMenuBar(const sf::Vector2f&, int&);
	bool handleClickOnBoard(sf::Vector2f&);


private:
	int m_length;
	int m_width;
};