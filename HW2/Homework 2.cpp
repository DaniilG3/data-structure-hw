#include <iostream>
#include "Deck.h"
#include "SidePile.h"

using namespace std;

void initialize_game(Deck& player_deck, Deck& computer_deck) {
    int player_initial[] = {3, 6, 7, 10, 4};
    int computer_initial[] = {5, 8, 2, 9, 3};

    for (int card : player_initial) {
        player_deck.enqueue(card);
    }
    for (int card : computer_initial) {
        computer_deck.enqueue(card);
    }
}

void display_card_counts(const Deck& player_deck, const Deck& computer_deck, const SidePile& player_side_pile, const SidePile& computer_side_pile) {
    cout << "Player Deck: " << player_deck.count() << " cards, Player Side Pile: " << player_side_pile.count() << " cards\n";
    cout << "Computer Deck: " << computer_deck.count() << " cards, Computer Side Pile: " << computer_side_pile.count() << " cards\n";
}

bool play_round(Deck& player_deck, Deck& computer_deck, SidePile& player_side_pile, SidePile& computer_side_pile) {
    int player_card1 = player_deck.dequeue();
    cout << "\nPlayer's top card: " << player_card1 << "\n";
    cout << "Player, choose: 1 to Push, 2 to Pull\n";
    int choice;
    cin >> choice;

    int player_card2 = 0;
    if (choice == 1) {
        player_side_pile.push(player_card1);
        player_card1 = player_deck.dequeue();
    }
    else if (choice == 2 && player_side_pile.count() > 0) {
        player_card2 = player_side_pile.pop();
    }

    int computer_card1 = computer_deck.dequeue();
    cout << "\nComputer's top card: " << computer_card1 << "\n";
    cout << "Computer, choose: 1 to Push, 2 to Pull\n";
    cin >> choice;

    int computer_card2 = 0;
    if (choice == 1) {
        computer_side_pile.push(computer_card1);
        computer_card1 = computer_deck.dequeue();
    }
    else if (choice == 2 && computer_side_pile.count() > 0) {
        computer_card2 = computer_side_pile.pop();
    }

    cout << "\nPlayer plays: " << player_card1;
    if (player_card2 > 0) cout << " and " << player_card2;
    cout << "\n";

    cout << "Computer plays: " << computer_card1;
    if (computer_card2 > 0) cout << " and " << computer_card2;
    cout << "\n";

    int player_total = player_card1 + player_card2;
    int computer_total = computer_card1 + computer_card2;

    if (player_total > computer_total) {
        cout << "Player wins the round\n";
        player_deck.enqueue(player_card1);
        if (player_card2 > 0) {
            player_deck.enqueue(player_card2);
        }
        player_deck.enqueue(computer_card1);
        if (computer_card2 > 0) {
            player_deck.enqueue(computer_card2);
        }
        display_card_counts(player_deck, computer_deck, player_side_pile, computer_side_pile);
        return true;
    }
    else {
        cout << "Computer wins the round\n";
        computer_deck.enqueue(player_card1);
        if (player_card2 > 0) {
            computer_deck.enqueue(player_card2);
        }
        computer_deck.enqueue(computer_card1);
        if (computer_card2 > 0) {
            computer_deck.enqueue(computer_card2);
        }
        display_card_counts(player_deck, computer_deck, player_side_pile, computer_side_pile);
        return false;
    }
}

int main() {
    Deck player_deck;
    Deck computer_deck;
    SidePile player_side_pile;
    SidePile computer_side_pile;

    initialize_game(player_deck, computer_deck);

    int choice;
    cout << "Choose play style:\n1. Play until one participant runs out of cards\n2. Play for a fixed number of rounds\n";
    cin >> choice;

    if (choice == 1) {
        cout << "You chose to play until one participant runs out of cards.\n";
        while (player_deck.count() > 0 || player_side_pile.count() > 0) {
            play_round(player_deck, computer_deck, player_side_pile, computer_side_pile);
            if (player_deck.count() == 0 && player_side_pile.count() == 0) {
                cout << "Computer wins the game!\n";
                return 0;
            }
            if (computer_deck.count() == 0 && computer_side_pile.count() == 0) {
                cout << "Player wins the game!\n";
                return 0;
            }
        }
    }
    else if (choice == 2) {
        int rounds;
        cout << "Enter the number of rounds: ";
        cin >> rounds;
        cout << "You chose to play for " << rounds << " rounds.\n";
        int player_wins = 0;
        int computer_wins = 0;
        for (int i = 0; i < rounds; ++i) {
            if (play_round(player_deck, computer_deck, player_side_pile, computer_side_pile)) {
                player_wins++;
            }
            else {
                computer_wins++;
            }
        }
        if (player_wins > computer_wins) {
            cout << "Player wins the game!\n";
        }
        else if (computer_wins > player_wins) {
            cout << "Computer wins the game!\n";
        }
        else {
            cout << "It's a tie, Computer wins the game by default!\n";
        }
    }
    else {
        cout << "Invalid choice.\n";
    }
}