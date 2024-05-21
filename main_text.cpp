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

	while (repeatcount != 3) {
		bool updatecount = true;

		while (updatecount) {
			updatecount = text.swapScreen();
		}
		repeatcount = text.initialScreen(predefined_puzzles);
	}

	return 0;
}