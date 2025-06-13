#include "Player.h"

#include <iomanip>

#include "HardModeW.h"


Player::Player(double initial_money, bool hard_mode) : money(initial_money) {
    if (hard_mode) {
        wheel = new HardModeW();
    } else {
        wheel = new Wheel();
    }
}

int Player::spinWheel(int playerResult) {
    if (HardModeW* hardWheel) {
        return hardWheel->spin(playerResult);
    } else {
        return wheel->spin();
    }
}
