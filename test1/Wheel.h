#pragma once

#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
private:
    int maxRange;

public:
    Wheel();

    int getRange();
    void setRange(int range);
    int spin();
};

#endif