#include "Player.h"

#include <iomanip>

Player::Player(double initialMoney) {
    money = initialMoney;
}


void Player::setMoney(double imoney) {
    money = imoney;
}

double const Player::getMoney() {
    return money;
}

int Player::spinWheel() {
    return wheel.spin();
}

int Player::spinWheel(bool playerResult) {
    return hardWheel.spin(playerResult);
}


double Player::roundToCents(double value) {
    return std::round(value * 100.0) / 100.0;
}
