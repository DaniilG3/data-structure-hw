#pragma once

#ifndef HARDWHEEL_H
#define HARDWHEEL_H

#include "Wheel.h"

using namespace std;

class HardWheel : public Wheel {
private: 
    int houseWins = 0;
    bool firstSpin = 0;

public:
    int spin(bool playerResult);
};

#endif