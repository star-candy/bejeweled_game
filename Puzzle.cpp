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
    srand((unsigned int)time(NULL));
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
    for (int y = 0; y < num_columns; y++) {
        for (int x = 0; x < num_rows; x++) {
            jewels[y][x] = getJewelType(jewel_list[jewel_list_set]);
            jewel_list_set++;
        }
    }
    return true;
}

void Puzzle::randomize() {
    srand((unsigned int)time(NULL));
    for (int y = 0; y < num_columns; y++) {
        for (int x = 0; x < num_rows; x++) {
            jewels[y][x] = Jewel(rand() % 7);
        }
    }
}

bool Puzzle::update() {
    static bool updateValidate = true;
    bool executeUpdate = false;
    if (updateValidate == true) {//true �� A��� ����
        updateValidate = false;
        identifyChain();
        executeUpdate = clearChain();
        return executeUpdate;
    }

    if (updateValidate == false) {//false �� B��� ����
        updateValidate = true;
        executeUpdate = fillJewels();
        chains.clear();
        return executeUpdate;
    }
    return executeUpdate;
}

bool Puzzle::validCount(int x, int y) {
    if (x < 0 || x >= num_rows) return false;
    if (y < 0 || y >= num_columns) return false;
    return true;
}

void Puzzle::identifyChain() {
    for (int y = 0; y < num_columns; ++y) {
        for (int x = 0; x < num_rows; ++x) {
            Jewel currentType = jewels[y][x];
            if (currentType != Jewel::NONE) {
                createChain(x, y, currentType);
            }
        }
    }
}

void Puzzle::createChain(int x, int y, Jewel currentType) {
    int rowCount = countChain(x, y, currentType, 1, 0);
    if (rowCount >= 3) {
        Chain chain;
        chain.jewel = currentType;
        chain.start.first = x;
        chain.start.second = y;
        chain.end.first = x + rowCount - 1;
        chain.end.second = y;
        chains.push_back(chain);
    }

    int colCount = countChain(x, y, currentType, 0, 1);
    if (colCount >= 3) {
        Chain chain;
        chain.jewel = currentType;
        chain.start.first = x;
        chain.start.second = y;
        chain.end.first = x;
        chain.end.second = y + colCount - 1;
        chains.push_back(chain);
    }
}

int Puzzle::countChain(int x, int y, Jewel currentType, int dx, int dy) {
    int count = 1;
    int nx = x + dx;
    int ny = y + dy;
    while (validCount(nx, ny) && jewels[ny][nx] == currentType) {
        count++;
        nx += dx;
        ny += dy;
    }
    return count;
}

bool Puzzle::clearChain() {
    for (const Chain& chain : chains) {
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

bool Puzzle::fillJewels() {//0.5�� ���� �Ϸ� x �� update ����� �Ǵ� ����, �� x y �ٲ�� �����ϴ°�? 
    bool executeCount = false;

    for (int y = 0; y < num_columns; y++) {
        int emptySpaces = 0;
        for (int x = num_rows - 1; x >= 0; x--) {
            if (jewels[y][x] == Jewel::NONE) { //���ο��� emptySpace ���� ���� �Ǵ�. (�� �� �Ǵܱ�ɿ��� �����ϳ�?)
                emptySpaces++;
                executeCount = true;
            }
            else if (emptySpaces > 0) { //�ᱹ �ϳ��� �������� NONE �������� �ϳ��� �����Ѵ�!!
                jewels[y][x + emptySpaces] = jewels[y][x];//���� empty���� �߽߰� ���̻� empty ������, empty�Ʒ��� ���� jewel �ű��
            }
        }
        for (int i = 0; i < emptySpaces; i++) {
            jewels[y][i] = Jewel(rand() % 7); // �� ���� �� ���� ����
        }
    }
    return executeCount;
}


bool Puzzle::coordinateValidate(std::pair<int, int>& loc) const {//const �Լ� getJewel�� ��� ���� const �±� �߰���
    bool validate = false;
    if (loc.first >= 0 && loc.first < num_rows) {
        if (loc.second >= 0 && loc.second < num_columns) {
            validate = true;
        }
    }
    return validate;
}

//��Ģ���� x y �� �� �ϳ��� 1���� �� �� ���� ����, �Ѵ� 1�̻� ���̴� �밢�� �ǹ���
bool Puzzle::swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc) {
    if (!coordinateValidate(prev_loc) || !coordinateValidate(next_loc)) return false;
    int xCount = abs(next_loc.first - prev_loc.first);
    int yCount = abs(next_loc.second - prev_loc.second);
    if (!((xCount == 1 && yCount == 0) || (xCount == 0 && yCount == 1))) return false;

    Jewel buffer = jewels[prev_loc.second][prev_loc.first]; //swap
    jewels[prev_loc.second][prev_loc.first] = jewels[next_loc.second][next_loc.first];
    jewels[next_loc.second][next_loc.first] = buffer;
    return true;
}

bool Puzzle::setJewel(std::pair<int, int> loc, Jewel jewel) {//loc �˻� �ʿ�
    if (!coordinateValidate(loc)) return false;
    int x = loc.first;
    int y = loc.second;

    jewels[y][x] = jewel;
    return true;
}

Jewel Puzzle::getJewel(std::pair<int, int> loc) const {
    if (!coordinateValidate(loc)) return Jewel::NONE;
    int x = loc.first;
    int y = loc.second;
    return jewels[y][x];
}

//----------- text ui function

void Text_Puzzle::jewelsToTextVector() {
    textJewels.clear();

    std::vector<char> textJewelColumns(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            textJewelColumns[j] = getJewelLetter(getJewel(std::make_pair(j, i)));
        }
        textJewels.push_back(textJewelColumns);
    }
}
