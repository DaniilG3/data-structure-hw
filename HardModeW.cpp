#include "HardModeW.h"
#include <cstdlib>
#include <iostream>

HardModeW::HardModeW() : Wheel(), consecutiveWins(0), currentRange(10) {}

// Overloaded spin method that accepts player's result
int HardModeW::spin(int playerResult) {
    int houseSpin = (rand() % currentRange) + 1;

    if (houseSpin > playerResult) {
        consecutiveWins++;
    } else {
        consecutiveWins = 0;  // Reset win streak if the house loses
        increaseRange();       // Increase range if the house loses
    }

    if (consecutiveWins >= 2) {
        decreaseRange();        // Decrease range if the house wins two times consecutively
    }

    return houseSpin;
}

// Method to increase the range
void HardModeW::increaseRange() {
    currentRange = std::min(currentRange + 10, 100);  // Cap the range at a maximum of 100
    std::cout << "House's range increased to 1-" << currentRange << std::endl;
}

// Method to decrease the range
void HardModeW::decreaseRange() {
    if (currentRange > 5) {  // Ensure the minimum range is 1-5
        currentRange = std::max(currentRange - 10, 5);
        std::cout << "House's range decreased to 1-" << currentRange << std::endl;
    }
}

