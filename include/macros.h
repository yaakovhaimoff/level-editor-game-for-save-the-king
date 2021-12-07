#pragma once

// amount of player tools in the game
const int numOfPlayers = 4;

// what the tiles in the game can posses

const auto BOARD_COLOR = sf::Color(199, 220, 227);
const auto MENU_COLOR = sf::Color(214, 217, 213);
const int CELL = 60;
const int SPACE = 3;
const int SIDE_WIDTH = 135;
const int SIDE_LENGTH = 180;
const int MenuBar = 14;


enum gameTools
{
	GateKey = 70,
	Fire = 42,
	Teleport = 88,
	Throne = 64,
	Tile = 33,
	Gate = 35,
	Space = 32,
	Wall = 61
};
// the moves which can happen in the game
enum gameMoves
{
	DoNothing = 0,
	ContinueAndDelete = 1,
	StepAndSaveKey = 2,
	JumpToTheNextTeleport = 3,
	ThiefHasKey = 4,
	GameOver = 5
};

enum steps
{
	Up = -1,
	Down = 1,
	Left = -1,
	Right = 1
};
// the player tools in the games
enum playersKeys
{
	KING = 75,      // 'K'
	MAGE = 77,     // 'M'
	WARRIOR = 87, // 'W'
	THIEF = 84    // 'T'
};
// the player key, and the escape buuton
enum Keys
{
	Playerp = 112,	 // 'p'
	PlayerP = 80,	 // 'P'
	KB_Escape = 27,
	SpecialKey = 224,
};
// arrows in the keyboard
enum SpecialKeys
{
	KB_Up = 72,
	KB_Down = 80,
	KB_Left = 75,
	KB_Right = 77,
};