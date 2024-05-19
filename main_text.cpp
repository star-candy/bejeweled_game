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
//initialScreen ������ main ��ü while ����
//���� swapScreen false ������ ���� �ݺ�  00 00 �Է� �� false ��µ� ��
// swap ���� �� initialScreen ��¹����� �����ϱ�
// ���� ���� ���ؼ��� �Լ� ���ο��� if error �Լ��� �����Ѵ�.