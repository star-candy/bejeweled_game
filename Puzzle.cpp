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

Puzzle::Puzzle(int num_rows, int num_columns) : num_rows{ num_rows }, num_columns{ num_columns } {
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
            jewels[i][j] = getJewelType(jewel_list[jewel_list_set]);
            jewel_list_set++;
        }
    }
    return true;
}

void Puzzle::randomize() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < num_columns; i++) {
        for (int j = 0; j < num_rows; j++) {
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
    /*for (int y = 0; y < num_rows; y++) {
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
    */
    for (int y = 0; y < num_rows; ++y) {
        for (int x = 0; x < num_columns; ++x) {
            Jewel currentType = jewels[y][x];
            if (currentType != Jewel::NONE) {
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
                        chain.end.first = nx - xChainCount[k]; // 마지막으로 검사된 좌표의 이전 좌표
                        chain.end.second = ny - yChainCount[k]; // 마지막으로 검사된 좌표의 이전 좌표
                        chains.push_back(chain);
                    }
                }
            }
        }
    }
}

bool Puzzle::clearChain(std::vector<Chain>& chains) {
    /*for (int chainsCount = 0; chainsCount < chains.size(); chainsCount++) {//vector 요소 찾기 size가 아닌가
        for (int y = chains[chainsCount].start.second; y < chains[chainsCount].end.second; y++) {
            for (int x = chains[chainsCount].start.first; x < chains[chainsCount].end.first; x++) {
                jewels[y][x] = Jewel::NONE;
            }
        }
    }*/
    
    for (Chain chain : chains) {
        int startX = chain.start.first;
        int startY = chain.start.second;
        int endX = chain.end.first;
        int endY = chain.end.second;

        for (int y = startY; y <= endY; ++y) {
            for (int x = startX; x <= endX; ++x) {
                jewels[y][x] = Jewel::NONE;
            }
        }
    }
        return true;
}

bool Puzzle::fillJewels() {
    bool executeCount = false;
    srand((unsigned int)time(NULL));
    for (int y = 0; y < num_columns; y++) {
        for (int x = 0; x < num_rows; x++) {
            if (jewels[y][x] == Jewel::NONE) {
                jewels[y][x] = Jewel(rand() % 7);
                executeCount = true;
            }
        }
    }
    return executeCount;
}

bool Puzzle::update() {
    bool executeUpdate = false;
    if (updateValidate == true) {//true 시 A기능 구현
        updateValidate = false;
        std::vector<Chain> chains;
        identifyChain(chains);
        executeUpdate = clearChain(chains);
        return executeUpdate;
    }

    if (updateValidate == false) {//false 시 B기능 구현
        updateValidate = true;
        executeUpdate = fillJewels();
        return executeUpdate;
    }
    return executeUpdate;
}

bool Puzzle::setJewel(std::pair<int, int> loc, Jewel jewel) {
    int x = loc.first;
    int y = loc.second;
    if (x < 0 || x >= num_rows) return false;
    if (y < 0 || y >= num_columns) return false;

    jewels[y][x] = jewel;
    return true;
}

Jewel Puzzle::getJewel(std::pair<int, int> loc) const {//loc 조건 검사 필요
    int x = loc.first;
    int y = loc.second;
    if (x >= 0 && x < num_rows && y >= 0 && y < num_columns) {//rows, columns 0으로 인식되는 문제
        return jewels[y][x];
    }

    return Jewel::NONE; // Puzzle_window의 loc에서 조건검사 이상
}

bool Puzzle::swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc) {
   /* if (prev_loc.first < 0 || prev_loc.first >= num_rows || next_loc.first < 0 || next_loc.first >= num_rows) return false;
    if (prev_loc.second < 0 || prev_loc.second >= num_columns || next_loc.second < 0 || next_loc.second >= num_columns) return false;
    int xCount = (prev_loc.first - next_loc.first) * (prev_loc.first - next_loc.first);
    int yCount = (prev_loc.second - next_loc.second) * (prev_loc.second - next_loc.second);
    if (xCount != 1 || yCount != 1) return false;
    */
    //규칙에서 x y 값 중 하나만 1차이 날 시 변경 가능, 둘다 1이상 차이는 대각을 의미함

    Jewel buffer = jewels[prev_loc.second][prev_loc.first];
    jewels[prev_loc.second][prev_loc.first] = jewels[next_loc.second][next_loc.first];
    jewels[next_loc.second][next_loc.first] = buffer;
    return true;
}
