#include "TileBoardObjects.h"

//________________________
WallObject::WallObject()
	: GameObjects("brickWall.png",
		SIDE_WIDTH + (CELL + SPACE) * 4, SPACE, WALL) {}

//_______________________
CrownObject::CrownObject()
	: GameObjects("crown.png",
		SIDE_WIDTH + (CELL + SPACE) * 5, SPACE, CROWN) {}

//______________________
FireObject::FireObject()
	: GameObjects("fire.png",
		SIDE_WIDTH + (CELL + SPACE) * 6, SPACE, FIRE) {}

//______________________
GateObject::GateObject()
	: GameObjects("gate.png",
		SIDE_WIDTH + (CELL + SPACE) * 7, SPACE, GATE) {}

//______________________
KeyeObject::KeyeObject()
	: GameObjects("key.png",
		SIDE_WIDTH + (CELL + SPACE) * 8, SPACE, GATE_KEY) {}

//____________________________
MonsterObject::MonsterObject()
	: GameObjects("monster.png",
		SIDE_WIDTH + (CELL + SPACE) * 9, SPACE, MONSTER) {}

//__________________________________
TeleporterObject::TeleporterObject()
	: GameObjects("teleport.png",
		SIDE_WIDTH + (CELL + SPACE) * 10, SPACE, TELEPORT) {}