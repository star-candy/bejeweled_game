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

	do{
		bool updateCount = true;

		while (updateCount) {
			updateCount = text.swapScreen();
		}
		repeatCount = text.initialScreen(predefined_puzzles);
		//update a���� update ��� ���� �� ���� update���� �ٷ� b ������� ���۵Ǵ� ����
		//static ī���͸� private ������ ����� while�� ����� �� true ����
	} while (repeatCount != 3 && repeatCount > 0 && repeatCount < 3);


	return 0;
}