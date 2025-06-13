#include "Wheel.h"

#include <iomanip>

Wheel::Wheel() {
    value = 10;
}

int Wheel::spin() {
    return (rand() % value) + 1;
}
