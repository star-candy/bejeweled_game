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
//initialScreen 값으로 main 전체 while 묶기
//내부 swapScreen false 전까지 무한 반복  00 00 입력 시 false 출력될 것
// swap 종료 시 initialScreen 출력문으로 복귀하기
// 내부 오류 대해서는 함수 내부에서 if error 함수로 관리한다.