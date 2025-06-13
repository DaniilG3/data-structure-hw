#include "HardModeW.h"

class Player {
private:
    Wheel* wheel;
    double money;

public:
    Player(double initial_money, bool hardMode = false);
    void setMoney(double imoney);
    double const getMoney();

    int spinWheel(int playerResult = 0);
    static double roundToCents(double value);
};
