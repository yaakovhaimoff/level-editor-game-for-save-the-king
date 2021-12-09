#include "PlayerObjects.h"

//______________________
KingObject::KingObject()
	: GameObjects("king.png",
		SIDE_WIDTH + (CELL + SPACE) * 0, SPACE, KING) {}

//______________________
MageObject::MageObject()
	: GameObjects("mage.png",
		SIDE_WIDTH + (CELL + SPACE) * 1, SPACE, MAGE) {}

//____________________________
WarriorObject::WarriorObject()
	: GameObjects("warrior.png",
		SIDE_WIDTH + (CELL + SPACE) * 2, SPACE, WARRIOR) {}

//________________________
ThiefObject::ThiefObject()
	: GameObjects("thief.png",
		SIDE_WIDTH + (CELL + SPACE) * 3, SPACE, THIEF) {}