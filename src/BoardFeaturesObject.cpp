#include "BoardFeaturesObject.h"

//________________________
EraseObject::EraseObject()
	: GameObjects("eraser.png",
		(CELL + SPACE)* ERASE_BOARD_OBJECT, SPACE, ERASE) {}

//______________________________
NewBoardObject::NewBoardObject()
	: GameObjects("newBoard.png",
		(CELL + SPACE)* NEW_BOARD_BOARD_OBJECT, SPACE, NEW_BOARD) {}

//_______________________________
SaveBoardObject::SaveBoardObject()
	: GameObjects("saveBoard.png",
		(CELL + SPACE)* SAVE_BOARD_BOARD_OBJECT, SPACE, SAVE_BOARD) {}
