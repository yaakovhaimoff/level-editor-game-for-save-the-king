#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "BuildBoard.h"
#include "PlayerObjects.h"
#include "TileBoardObjects.h"
#include "BoardFeaturesObject.h"
#include "macros.h"


class ManageBoard
{
public:
	ManageBoard();
	void runBoard();
	void printWindow(sf::RenderWindow&)const;
	void printObjects(sf::RenderWindow&)const;
	void addObject(int, sf::Vector2f&);

private:
	void getBoardSizeFromUser();

	BuildBoard m_board;
	KingObject m_king;
	MageObject m_mage;
	WarriorObject m_warrior;
	ThiefObject m_thief;
	WallObject m_wall;
	CrownObject m_crown;
	FireObject m_fire;
	GateObject m_gate;
	KeyeObject m_key;
	MonsterObject m_monster;
	TeleporterObject m_teleport;
	EraseObject m_erase;
	NewBoardObject m_newBoard;
	SaveBoardObject m_saveBoard;

};