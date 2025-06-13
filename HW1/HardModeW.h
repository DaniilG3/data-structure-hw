#pragma once
#include "Wheel.h"

#ifndef HARD_MODE_WHEEL_H
#define HARD_MODE_WHEEL_H

class HardModeW : public Wheel {
private:
    int consecutiveWins;
    int currentRange;

public:
    HardModeW(); // Constructor initializes with default range and win count
    int spin(int playerResult); // Overload spin method to account for player result

    void increaseRange();  // Increases the range of the wheel
    void decreaseRange();  // Decreases the range of the wheel
};
#endif
