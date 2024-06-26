#pragma once

#include "std_lib_facilities.h"
#include <utility>
#include <string>
#include <vector>

enum class Jewel
{
	NONE=-1, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, WHITE
};

class Puzzle
{
public:
	struct Chain //체인 발생 시 Chain 객체 생성, type과 시작, 종료 지점 명시
	{//update에서 chain vector로 전체 chain 식별 가능해보임 
		Jewel jewel;
		std::pair<int, int> start;
		std::pair<int, int> end;
	};

	Puzzle(int num_rows, int num_columns);

	bool initialize(const std::string& jewel_list);
	void randomize();
	bool update();

	bool coordinateValidate(std::pair<int, int>& loc) const;

	bool swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc);
	
	bool setJewel(std::pair<int, int> loc, Jewel jewel);
	Jewel getJewel(std::pair<int, int> loc) const;

	inline int getNumRows() const { return num_rows; }
	inline int getNumColumns() const { return num_columns; }

	static Jewel getJewelType(char letter);
	static char getJewelLetter(Jewel jewel);
	
private:
	int num_rows;
	int num_columns;
	bool updateValidate = true;
	std::vector<std::vector<Jewel>> jewels; //8*8 전체 jewel 저장 벡터
	std::vector<Chain> chains;
	bool validCount(int x, int y);
	void identifyChain();
	void createChain(int x, int y, Jewel currentType);
	int countChain(int x, int y, Jewel currentType, int dx, int dy);
	bool clearChain();
	bool fillJewels();
};


//text ui 사용 함수
class Text_Puzzle : public Puzzle {
public:
	Text_Puzzle(int num_rows, int num_columns);

	void printTextJewels();
	void initialScreen(vector<string>& predefined_puzzles, int& repeatCount);
	void swapScreen(bool& updateCount);
private:
	std::vector<std::vector<char>> textJewels; //8 * 8 전체 jewel을 text type으로 저장 벡터
	void jewelsToTextVector();
};