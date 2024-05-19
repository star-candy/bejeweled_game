#include "Puzzle.h"

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> predefined_puzzles = {
	"!#!&%*&@&!@&!!@#!@$$**%!&!&&!##&#*@$&@$%%$$*&*@$##$#@$%@#$&#%$@#",
	"#!%%@%!&@*%!&@&!#*$$%%%&#*$#@$@!$%$@%@&!%$&%&@*%*$&&*&#!$$&*$#*!",
	"*@&*@#%%&%%&!$!*%#%*!*##*$$###*$$!#&&@*$$@#&#$&$$#!!!**@##@@@!!!",
	"$#@!%@$#$&$&!!*@@!$$@$!&*@**&$&@$!#*@&*@&###!@@%&@&!%&&%##$#@@&$",
};

// Declare and define as many functions as necessary

int main()
{
	Text_Puzzle text(8, 8);

	int repeatCount = text.initialScreen(predefined_puzzles);
	bool updateCount = true;
	do{


		while (updateCount) {
			updateCount = text.swapScreen();
		}
		repeatCount = text.initialScreen(predefined_puzzles);


	} while (repeatCount != 3 && repeatCount > 0 && repeatCount < 3);

	// Implement text-based UI for playing Bejeweled game as required

	return 0;
}
// 중력 좌우 변경 문제 발생, 상 하 중력으로 변경 필요