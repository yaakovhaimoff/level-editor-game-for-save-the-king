#include "PlayerObjects.h"

//______________________
KingObject::KingObject()
	: GameObjects("king.png",
		(CELL + SPACE)* KING_BOARD_OBJECT, SPACE, KING) {}

//______________________
MageObject::MageObject()
	: GameObjects("mage.png",
		(CELL + SPACE)* MAGE_BOARD_OBJECT, SPACE, MAGE) {}

//____________________________
WarriorObject::WarriorObject()
	: GameObjects("warrior.png",
		(CELL + SPACE)* WARRIOR_BOARD_OBJECT, SPACE, WARRIOR) {}

//________________________
ThiefObject::ThiefObject()
	: GameObjects("thief.png",
		(CELL + SPACE)* THIEF_BOARD_OBJECT, SPACE, THIEF) {}