#include "BoardFeaturesObject.h"

//________________________
EraseObject::EraseObject()
	: GameObjects("eraser.png",
		SIDE_WIDTH + (CELL + SPACE) * 11, SPACE, ERASE) {}

//______________________________
NewBoardObject::NewBoardObject()
	: GameObjects("newBoard.png",
		SIDE_WIDTH + (CELL + SPACE) * 12, SPACE, NEW_BOARD) {}

//_______________________________
SaveBoardObject::SaveBoardObject()
	: GameObjects("saveBoard.png",
		SIDE_WIDTH + (CELL + SPACE) * 13, SPACE, SAVE_BOARD) {}