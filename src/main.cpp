#include <SFML/Graphics.hpp>

#include <iostream>
#include "ManageWindow.h"

int main()
{
	auto game = ManageWindow();
	game.runBoard();

	return EXIT_SUCCESS;
}
