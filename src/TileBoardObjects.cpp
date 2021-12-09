#include "TileBoardObjects.h"

//______________________
WallObject::WallObject()
	: GameObjects("brickWall.png",
		(CELL + SPACE)* WALL_BOARD_OBJECT, SPACE, WALL) {}

//_______________________
CrownObject::CrownObject()
	: GameObjects("crown.png",
		(CELL + SPACE)* CROWN_BOARD_OBJECT, SPACE, CROWN) {}

//______________________
FireObject::FireObject()
	: GameObjects("fire.png",
		(CELL + SPACE)* FIRE_BOARD_OBJECT, SPACE, FIRE) {}

//______________________
GateObject::GateObject()
	: GameObjects("gate.png",
		(CELL + SPACE)* GATE_BOARD_OBJECT, SPACE, GATE) {}

//______________________
KeyeObject::KeyeObject()
	: GameObjects("key.png",
		(CELL + SPACE)* GATE_KEY_BOARD_OBJECT, SPACE, GATE_KEY) {}

//____________________________
MonsterObject::MonsterObject()
	: GameObjects("monster.png",
		(CELL + SPACE)* MONSTER_BOARD_OBJECT, SPACE, MONSTER) {}

//__________________________________
TeleporterObject::TeleporterObject()
	: GameObjects("teleport.png",
		(CELL + SPACE)* TELEPORT_BOARD_OBJECT, SPACE, TELEPORT) {}