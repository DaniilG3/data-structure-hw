#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
#include "Player.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed

    double initialMoney;
    char exit = 'Y';
    char hardModeChoice;

    cout << "Enter your initial amount: " << endl;
    cin >> initialMoney;

    cout << "Do you want to enable Hard Mode? (Y/N): ";
    cin >> hardModeChoice;
    hardModeChoice = toupper(hardModeChoice);

    bool hardMode = (hardModeChoice == 'Y');
    Player player(initialMoney, hardMode);

    while (exit == 'Y' && player.getMoney() > 0) {
        double bet;
        char type;

        while (true) {
            cout << "Enter your bet (minimum: 6, maximum: 20): " << endl;
            cin >> bet;

            if (bet < 6 || bet > 20) {
                cout << "Invalid bet amount. Please enter a value between 6 and 20." << endl;
            }
            else if (bet > player.getMoney()) {
                cout << "Invalid bet amount. Please enter a value less than or equal to your current balance." << endl;
            }
            else {
                break;
            }
        }

        int pball = player.spinWheel();  // Player's result
        int hball1 = player.spinWheel(pball);  // House's result (in hard mode)

        cout << "Do you want to double (D), halve (H), or keep (K) your wager? ";
        cin >> type;
        type = toupper(type);

        double change;

        switch (type) {
        case 'D':
            cout << "Player spun: " << pball << endl;
            cout << "House spun: " << hball1 << endl;
            if (hball1 > pball) {
                change = player.getMoney() - (2 * bet);
                player.setMoney(Player::roundToCents(change));
                cout << "House wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
            }
            else {
                change = player.getMoney() + (2 * bet);
                player.setMoney(Player::roundToCents(change));
                cout << "Player wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
            }
            break;

        case 'H':
            cout << "Player spun: " << pball << endl;
            cout << "House spun: " << hball1 << endl;
            if (hball1 > pball) {
                change = player.getMoney() - (bet / 2);
                player.setMoney(Player::roundToCents(change));
                cout << "House wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
            }
            else {
                change = player.getMoney() + (bet / 2);
                player.setMoney(Player::roundToCents(change));
                cout << "Player wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
            }
            break;

        default:
            cout << "Player spun: " << pball << endl;
            cout << "House spun: " << hball1 << endl;
            if (hball1 > pball) {
                change = player.getMoney() - bet;
                player.setMoney(Player::roundToCents(change));
                cout << "House wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
            }
            else {
                change = player.getMoney() + bet;
                player.setMoney(Player::roundToCents(change));
                cout << "Player wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
            }
            break;
        }

        if (player.getMoney() <= 0) {
            cout << "You have run out of money! Game over." << endl;
            break;
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> exit;
        exit = toupper(exit);
    }

    return 0;
}
