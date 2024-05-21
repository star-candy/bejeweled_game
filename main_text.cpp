#include "puzzle.h"

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> predefined_puzzles = {
	"!#!&%*&@&!@&!!@#!@$$**%!&!&&!##&#*@$&@$%%$$*&*@$##$#@$%@#$&#%$@#",
	"#!%%@%!&@*%!&@&!#*$$%%%&#*$#@$@!$%$@%@&!%$&%&@*%*$&&*&#!$$&*$#*!",
	"*@&*@#%%&%%&!$!*%#%*!*##*$$###*$$!#&&@*$$@#&#$&$$#!!!**@##@@@!!!",
	"$#@!%@$#$&$&!!*@@!$$@$!&*@**&$&@$!#*@&*@&###!@@%&@&!%&&%##$#@@&$",
};

// declare and define as many functions as necessary

int main()
{
	Text_Puzzle text(8, 8);

	int repeatcount = text.initialScreen(predefined_puzzles);
	if (repeatcount == 3) return 0;
	do{
		bool updatecount = true;

		while (updatecount) {
			updatecount = text.swapScreen();
		}
		repeatcount = text.initialScreen(predefined_puzzles);

	} while (repeatcount != 3 && repeatcount > 0 && repeatcount < 3);

	return 0;
}