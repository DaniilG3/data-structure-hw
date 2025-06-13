#include "Shelf.h"
#include <iostream>
using namespace std;

void addShow(Shelf& shelf) {
    string title, description;
    cout << "Name of Show: ";
    cin.ignore();
    getline(cin, title);
    cout << "Description of Show: ";
    getline(cin, description);
    Show newShow(title, description);

    try {
        shelf.add(newShow);
    } catch (const FullShelf& e) {
        cout << e.what() << endl;
    }
}

void removeShow(Shelf& shelf) {
    try {
        Show removedShow = shelf.remove();
        cout << "The details of the removed show: ";
        removedShow.details();
    } catch (const EmptyShelf& e) {
        cout << e.what() << endl;
    }
}

void displayMenu() {
    cout << "Press 1 to add a show to the shelf." << endl;
    cout << "Press 2 to remove a show from the shelf." << endl;
    cout << "Press 3 to see how many shows are currently on the shelf." << endl;
    cout << "Press 4 to quit." << endl;
}

int main() {
    Shelf shelf;
    char choice;

    do {
        displayMenu();
        int option;
        cout << "Press: ";
        cin >> option;

        switch (option) {
            case 1:
                addShow(shelf);
            break;
            case 2:
                removeShow(shelf);
            break;
            case 3:
                cout << "The number of shows on the shelf: " << shelf.numInShelf() << endl;
            break;
            case 4:
                cout << "Exiting the program." << endl;
            return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << endl;
        cout << "Run again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
