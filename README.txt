Edit level
Yaakov Haimoff 318528510

In this project we build a graphic board with the objects
from save the king game we've made on exercise 2.

If there's no board existing in the folder, 
the user will build his own board.
In the board there are 14 objects, which are characters , tiles and board
management tools for example erase.
The user can't enter more then once the same character, or place any sort of object on 
a spot which is elready taken. But tiles he can enter as many as he wants, except from the crown.
In case there's a board in the folder, the file will be displayes on the board
as in the file, and he'll be able to continue on editing it if he'd like too.
When the user chooses to save the board he has build, the board will be saved in a file named
"Board.txt", which will be in the out folder.

files in the project:
include - where all the headers are stalled.
src - where all the cpp are stalled, the class implementation are and the main.
README.txt - where the explaing of the project is.

In the project I made use with enheritance, the base class is GameObjects, which all the objects
inherit her members and functionalities.
Every object has to show it self and store its locations on the board, there for all the objects
in the program will inherit this features and more from the base class.

No algorithm worth mentioning. 
No bugs I'm aware of.
