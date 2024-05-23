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
    for (int y = 0; y < num_columns; y++) {
        for (int x = 0; x < num_rows; x++) {
            jewels[y][x] = Jewel(rand() % 7);
        }
    }
}

bool Puzzle::update() {
    bool executeUpdate = false;
    if (updateValidate == true) {//true 시 A기능 구현
        identifyChain();
        if (clearChain()) {
            executeUpdate = true;
            updateValidate = false;
        }
        return executeUpdate;
    }

    if (updateValidate == false) {//false 시 B기능 구현
        if (fillJewels()) {
            executeUpdate = true;
            updateValidate = true;
        }

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

int Puzzle::countChain(int x, int y, Jewel currentType, int nextX, int nextY) {
    int count = 1;
    int nx = x + nextX;
    int ny = y + nextY;
    while (validCount(nx, ny) && jewels[ny][nx] == currentType) {
        count++;
        nx += nextX;
        ny += nextY;
    }
    return count;
}

bool Puzzle::clearChain() {
    for (int i = 0; i < chains.size(); i++) {
        Chain& chain = chains[i];
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
    if (chains.size() == 0) return false;
    return true;
}

bool Puzzle::fillJewels() {
    bool executeCount = false;

    for (int x = 0; x < num_columns; x++) {
        int emptySpaces = 0;
        for (int y = num_rows - 1; y >= 0; y--) {
            if (jewels[y][x] == Jewel::NONE) { //세로열에 emptySpace 존재 여부 판단. 좌 하단부터 상위로 검증
                emptySpaces++;
                executeCount = true;
            }
            else if (emptySpaces > 0) { //하나의 열에서는 NONE 열이 하나만 존재한다!!
                jewels[y + emptySpaces][x] = jewels[y][x];//empty공간 발견시 더이상 empty 없을것, empty아래로 상위 jewel 옮기기
            }
        }
        for (int i = 0; i < emptySpaces; i++) {
            jewels[i][x] = Jewel(rand() % 7); // 맨 위에 새 보석 생성
        }
    }
    return executeCount;
}

bool Puzzle::coordinateValidate(std::pair<int, int>& loc) const {
    bool validate = false;
    if (loc.first >= 0 && loc.first < num_rows) {
        if (loc.second >= 0 && loc.second < num_columns) {
            validate = true;
        }
    }
    return validate;
}

//규칙에서 x y 값 중 하나만 1차이 날 시 변경 가능, 둘다 1이상 차이는 대각을 의미함
bool Puzzle::swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc) {
    if (!coordinateValidate(prev_loc) || !coordinateValidate(next_loc)) return false;
    int xCount = abs(next_loc.first - prev_loc.first);
    int yCount = abs(next_loc.second - prev_loc.second);
    if (!((xCount == 1 && yCount == 0) || (xCount == 0 && yCount == 1))) return false;

    Jewel buffer = jewels[prev_loc.first][prev_loc.second]; //swap
    jewels[prev_loc.first][prev_loc.second] = jewels[next_loc.first][next_loc.second];
    jewels[next_loc.first][next_loc.second] = buffer;
    return true;
}


bool Puzzle::setJewel(std::pair<int, int> loc, Jewel jewel) {//loc 검사 필요
    if (!coordinateValidate(loc)) return false;
    int y = loc.first;
    int x = loc.second;

    jewels[y][x] = jewel;
    return true;
}

Jewel Puzzle::getJewel(std::pair<int, int> loc) const {
    if (!coordinateValidate(loc)) return Jewel::NONE;
    int y = loc.first;
    int x = loc.second;
    return jewels[y][x];
}

//----------- text ui function
Text_Puzzle::Text_Puzzle(int num_rows, int num_columns) : Puzzle(num_rows, num_columns) {
    // 자식 객체 생성 위해 자식 class 생성자에 부모 class 생성자 초기화 기능 제공 -> 자식 객체 사용 가능
}

void Text_Puzzle::jewelsToTextVector() {
    textJewels.clear();

    std::vector<char> textJewelColumns(getNumColumns());
    for (int i = 0; i < getNumColumns(); i++) {
        for (int j = 0; j < getNumRows(); j++) {
            textJewelColumns[j] = getJewelLetter(getJewel(std::make_pair(j, i)));
        }
        textJewels.push_back(textJewelColumns);
    }
}
 
void Text_Puzzle::printTextJewels() {
    jewelsToTextVector();

    std::cout << "   0 1 2 3 4 5 6 7\n  +---------------\n";
    for (int y = 0; y < getNumColumns(); y++) {
        cout << y << " |";
        for (int x = 0; x < getNumRows(); x++) {
            cout << textJewels[x][y] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Text_Puzzle::initialScreen(vector<string>& predefined_puzzles, int& repeatCount) {
    //int input = 0;
    try {
        cout << "<<< BEJEWELED >>>\n\n";
        cout << "[1] Start a new random puzzle\n";
        cout << "[2] Start a pre-defined random puzzle\n";
        cout << "[3] Exit\n\n";

        cout << "> Choose a menu option (1~3): ";
        cin >> repeatCount;
        cout << "\n";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 제거
            error("정수형의 값이 입력되어야 합니다.");
        }
        if (repeatCount < 1 || repeatCount > 3) error("1~3 사이 정수가 입력되어야 합니다.");

        if (repeatCount == 1) {
            randomize();
            printTextJewels();
            while (update()) {
                printTextJewels();
            }
            return;
        }
        if (repeatCount == 2) {
            int predPuzzle;
            cout << ">Choose a puzzle option (0~3): ";
            cin >> predPuzzle;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 제거
                error("정수형의 값이 입력되어야 합니다.");
            }
            cout << "\n";

            if (predPuzzle < 0 || predPuzzle > 3) error("0~3 사이의 정수가 입력되어야 합니다.");

            initialize(predefined_puzzles[predPuzzle]);
            printTextJewels();
            while (update()) {
                printTextJewels();
            }
            return;
        }
        if (repeatCount == 3) {
            return;
        }
    }
    catch (runtime_error& e) {
        cout << e.what() << "\n\n";
        initialScreen(predefined_puzzles, repeatCount);
    }
}

void Text_Puzzle::swapScreen(bool& updateCount) {
    try {
        int firstX, secondX, firstY, secondY;

        cout << "input the first swap position (row, col):";
        cin >> firstX >> firstY;
        cout << "\n";
        cout << "input the second swap position (row, col):";
        cin >> secondX >> secondY;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 제거
            error("정수형의 값이 입력되어야 합니다.");
        }
        cout << "\n";

        if (firstX == 0 && secondX == 0 && firstY == 0 && secondY == 0) {
            updateCount = false;
            return;
        }

        pair<int, int> prev = make_pair(firstY, firstX);
        pair<int, int> next = make_pair(secondY, secondX);

        if (!swapJewels(prev, next)) {
            error("적절한 이동 위치가 아닙니다.");
        }

        printTextJewels();
        while (update()) {
            printTextJewels();
        }

        return;
    }
    catch (runtime_error& e) {
        cout << e.what() << "\n\n";
        swapScreen(updateCount);
    }
}



