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


