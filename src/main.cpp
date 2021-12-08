#include <SFML/Graphics.hpp>

#include <iostream>
#include "ManageBoard.h"

int main()
{
	auto game = ManageBoard();
	game.runBoard();

	return EXIT_SUCCESS;
}
