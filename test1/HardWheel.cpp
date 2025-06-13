#include "HardWheel.h"
#include <cstdlib>
#include <utility>
#include <iostream>

using namespace std;

int HardWheel::spin(bool playerResult) {
    if (firstSpin == 0) {
        if (playerResult == true) {
            houseWins -= 1;
            std::cout << houseWins << endl;
        }
        else {
            houseWins += 1;
        }

        if (houseWins <= -2) {
            setRange(getRange() * 2);
            houseWins = 0;
            std::cout << "The stakes are higher! House's range has been doubled from " << getRange() / 2 <<" to " << getRange() << endl;
        }

        if (houseWins >= 2) {
            setRange(getRange() / 2);
            houseWins = 0;
            std::cout << "The stakes are lower. House's range has been decreased from " << getRange() * 2 << " to " << getRange() << endl;
        }
        firstSpin = 1;
    }
    else {
        firstSpin = 0;
    }

    return (rand() % getRange() + 1);
}
