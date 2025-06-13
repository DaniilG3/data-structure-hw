#include "Wheel.h"

#include <iomanip>

Wheel::Wheel() {
    maxRange = 10;
}

int Wheel::spin() {
    return (rand() % maxRange + 1);
}

int Wheel::getRange() {
    return maxRange;
}

void Wheel::setRange(int range) {
    maxRange = range;
}