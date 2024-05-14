#include "Puzzle.h"

char Puzzle::getJewelLetter(Jewel jewel) {
    char letter = ' ';
    
    switch (jewel) {
    case Jewel::NONE: letter = ' ';     break;	
    case Jewel::RED: letter = '@';      break;	
    case Jewel::ORANGE: letter = '#';   break;
    case Jewel::YELLOW: letter = '*';   break;	
    case Jewel::GREEN: letter = '%';    break;	
    case Jewel::BLUE: letter = '$';     break;	
    case Jewel::PURPLE: letter = '&';   break;	
    case Jewel::WHITE: letter = '!';    break;	
    }
    return letter;
}

Jewel Puzzle::getJewelType(char letter) {
    Jewel jewel = Jewel::NONE;

    switch (letter) {
    case ' ': jewel = Jewel::NONE; break;
    case '@': jewel = Jewel::RED; break;
    case '#': jewel = Jewel::ORANGE; break;
    case '*': jewel = Jewel::YELLOW; break;
    case '%': jewel = Jewel::GREEN; break;
    case '$': jewel = Jewel::BLUE; break;
    case '&': jewel = Jewel::PURPLE; break;
    case '!': jewel = Jewel::WHITE; break;
    }
    return jewel;
}

Puzzle::Puzzle(int num_rows, int num_columns) {
    for (int i = 0; i < num_rows; i++) {
        std::vector<Jewel> insideJewels;
        for (int j = 0; j < num_columns; j++) {
            insideJewels.push_back(Jewel::NONE);
        }
        jewels.push_back(insideJewels);
    }
}

bool Puzzle::initialize(const std::string& jewel_list) {
    int jewelsLength = num_columns * num_rows;
    if (jewel_list.length() != jewelsLength) return false;

    int jewel_list_set = 0;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            jewels[j][i] = getJewelType(jewel_list[jewel_list_set]);
            jewel_list_set++;
        }
    }
    return true;
}

void Puzzle::randomize() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            jewels[i][j] = Jewel(rand() % 7);
        }
    }
}

bool Puzzle::validCount(int x, int y) {
    if (x < 0 || x >= num_columns) return false;
    if (y < 0 || y >= num_rows) return false;
    return true;
}

void Puzzle::identifyChain(std::vector<Chain>& chains) {
    for (int y = 0; y < num_rows; y++) {
        for (int x = 0; x < num_columns; x++) {
            Jewel currentType = jewels[y][x];
            for (int k = 0; k < 4; ++k) {
                int count = 1;
                int nx = x + xChainCount[k];
                int ny = y + yChainCount[k];
                while (validCount(nx, ny) && jewels[ny][nx] == currentType) {
                    count++;
                    nx += xChainCount[k];
                    ny += yChainCount[k];
                }
                if (count >= 3) {
                    Chain chain;
                    chain.jewel = currentType;
                    chain.start.first = x;
                    chain.start.second = y;
                    chain.end.first = nx;
                    chain.end.second = ny;
                    chains.push_back(chain);
                }
            }
        }
    }
}

void Puzzle::clearChain(std::vector<Chain>& chains) {
    for (int chainsCount = 0; chainsCount < chains.size(); chainsCount++) {
        for (int y = chains[chainsCount].start.second; y < chains[chainsCount].end.second; y++) {
            for (int x = chains[chainsCount].start.first; x < chains[chainsCount].end.first; x++) {
                jewels[y][x] = Jewel::NONE;
            }
        }
    }
}

void Puzzle::fillJewels() {

}

bool Puzzle::update() {
    static bool kindValidate = true;//�Լ� ���� �� true, false value ����ؾ� A, B ���� ���� ����
    if (kindValidate == true) {//true �� A��� ����
        kindValidate = false;
        std::vector<Chain> chains;
        identifyChain(chains);
        clearChain(chains);

        return true;
    }

    if (kindValidate == false) {//false �� B��� ����
        kindValidate == true;


        return true;
    }

}
