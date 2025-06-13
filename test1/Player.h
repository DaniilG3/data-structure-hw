#pragma once
#include "Wheel.h"
#include "HardWheel.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    bool hardMode;
    HardWheel hardWheel;
    Wheel wheel;
    double money;

public:
    Player(double initialMoney);
    void setMoney(double imoney); // Changes player's money
    double const getMoney(); // Gives current value of player's money
    int spinWheel(); // Gives a random value from [1 to 10]
    int spinWheel(bool playerResult);
    static double roundToCents(double value); // Rounds value up (only matters if the player enters a double value for money)
};


#endif