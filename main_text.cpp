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

	int repeatCount = 3;
	text.initialScreen(predefined_puzzles, repeatCount);

	while (repeatCount != 3) {
		bool updateCount = true;

		while (updateCount) {
			text.swapScreen(updateCount);
		}
		text.initialScreen(predefined_puzzles, repeatCount);

	}

	return 0;
}