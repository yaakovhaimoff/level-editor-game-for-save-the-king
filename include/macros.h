#pragma once

#include <string>

// amount of player tools in the game
const int numOfPlayers = 4;

// what the tiles in the game can posses

const auto BOARD_COLOR = sf::Color(199, 220, 227);
const auto MENU_COLOR = sf::Color(214, 217, 213);
const auto BACKGROUND_COLOR = sf::Color(217, 255, 255);
const int CELL = 60;
const int SPACE = 3;
const int SIDE_WIDTH = 135;
const int SIDE_LENGTH = 180;
const int MenuBar = 14;
const int PLAYER_EXIST = 2;

const std::string FILES_NAMES[] = { "king.png", "mage.png", "thief.png", "warrior.png", "crown.png", "gate.png", "fire.png",
										"key.png", "monster.png", "teleport.png", "brickWall.png", "eraser.png",
										"newBoard.png", "saveBoard.png" };
// 
// the player tools in the games
enum playersKeys
{
	KING = 75,      // 'K'
	MAGE = 77,     // 'M'
	WARRIOR = 87, // 'W'
	THIEF = 84    // 'T'
};

// what the tiles in the game can posses
enum gameTools
{
	ERASE = 1,
	NEW_BOARD = 2,
	SAVE_BOARD = 3,
	GATE_KEY = 70,
	FIRE = 42,
	TELEPORT = 88,
	CROWN = 64,
	MONSTER = 33,
	GATE = 35,
	WALL = 61
};

enum BoardRectObjects
{
	KING_BOARD_OBJECT = 0,    
	MAGE_BOARD_OBJECT = 1,
	WARRIOR_BOARD_OBJECT = 2,
	THIEF_BOARD_OBJECT = 3,
	WALL_BOARD_OBJECT = 4,
	CROWN_BOARD_OBJECT = 5,
	FIRE_BOARD_OBJECT = 6,
	GATE_BOARD_OBJECT = 7,
	GATE_KEY_BOARD_OBJECT = 8,
	MONSTER_BOARD_OBJECT = 9,
	TELEPORT_BOARD_OBJECT = 10,
	ERASE_BOARD_OBJECT = 11,
	NEW_BOARD_OBJECT = 12,
	SAVE_BOARD_OBJECT = 13,
	DO_NOTHING = 14
};
