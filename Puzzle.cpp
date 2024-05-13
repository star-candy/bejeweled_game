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
    int jewelsSize = num_rows * num_columns;
    for (int i = 0; i < jewelsSize; i++) {
        jewels.push_back(Jewel::NONE);
    }
}

bool Puzzle::initialize(const std::string& jewel_list) {
    if (jewel_list.length() != 64) return false;

    for (int i = 0; i < 64; i++) {
        jewels[i] = getJewelType(jewel_list[i]);
    }
    return true;
}
