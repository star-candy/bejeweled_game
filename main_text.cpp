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

	do{
		bool updatecount = true;

		while (updatecount) {
			updatecount = text.swapScreen();
		}
		repeatcount = text.initialScreen(predefined_puzzles);
		//update a에서 update 기능 종료 시 다음 update에서 바로 b 기능으로 시작되는 문제
		//static 카운터를 private 변수로 만들고 while문 재시작 시 true 선언
	} while (repeatcount != 3 && repeatcount > 0 && repeatcount < 3);


	return 0;
}