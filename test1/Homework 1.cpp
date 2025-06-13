#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Player.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL)); // Randomizes rand() seed

    double initialMoney; // Player's initial  money
    char exit = 'Y'; // Exit flag
    bool hardModeBool; // HardMode bool for setting up hard mode.
    int initial = 0; // Prevents the main function from using HardWheel's overloaded spin function until the first bet has gone through.
    bool playerResult; // Player's result (win or lose)
    int houseWins = 0; // For keeping track of current win streak while playing hard mode
    

    cout << "Enter your initial amount: " << endl;
    cin >> initialMoney; // Sets initial money for player

    Player player(initialMoney); // Creates a player instance

    // Asks the player if they want to play in hard mode, will turn if they choose yes.

    cout << "Do you want to play in hard mode? (Y/N): ";
    char hardModeChoice;
    cin >> hardModeChoice;
    hardModeChoice = toupper(hardModeChoice);
    hardModeBool = (hardModeChoice == 'Y');
    if (hardModeBool == true) {
        cout << "Hard mode has been activated\n";
    }

   

    while (exit == 'Y' && player.getMoney() > 0) {
        double bet;
        char type;

        //Ball values for house and player
        int hball1;
        int hball2;
        int pball;


        if (hardModeBool == true && initial != 0){
            hball1 = player.spinWheel(playerResult);
            hball2 = player.spinWheel(playerResult);
            pball = player.spinWheel();
        
        }
        else {
            hball1 = player.spinWheel();
            hball2 = player.spinWheel();
            pball = player.spinWheel();
        }

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

        cout << "Do you want to double (D), halve (H), or keep (K) your wager? ";
        cin >> type;
        type = toupper(type);

        double change;

        switch (type) {
        case 'D':
            cout << "Player spun: " << pball << endl;
            cout << "House spun: " << hball1 << " and " << hball2 << endl;
            if ((hball1 > pball) || (hball2 > pball)) {
                change = player.getMoney() - (2 * bet);
                player.setMoney(Player::roundToCents(change));
                cout << "House wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
                playerResult = false;
            }
            else {
                change = player.getMoney() + (2 * bet);
                player.setMoney(Player::roundToCents(change));
                cout << "Player wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
                playerResult = true;
            }
            break;

        case 'H':
            cout << "Player spun: " << pball << endl;
            cout << "House spun: " << hball1 << " and " << hball2 << endl;
            if ((hball1 > pball) && (hball2 > pball)) {
                change = player.getMoney() - (bet / 2);
                player.setMoney(Player::roundToCents(change));
                cout << "House wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
                playerResult = false;
            }
            else {
                change = player.getMoney() + (bet / 2);
                player.setMoney(Player::roundToCents(change));
                cout << "Player wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
                playerResult = true;
            }
            break;

        default:
            cout << "Player spun: " << pball << endl;
            cout << "House spun: " << hball1 << endl;
            if (hball1 > pball) {
                change = player.getMoney() - bet;
                player.setMoney(Player::roundToCents(change));
                cout << "House wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
                playerResult = false;
            }
            else {
                change = player.getMoney() + bet;
                player.setMoney(Player::roundToCents(change));
                cout << "Player wins! New balance: $" << fixed << setprecision(2) << player.getMoney() << endl;
                playerResult = true;
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
        initial = 1;
    }

    return 0;
}