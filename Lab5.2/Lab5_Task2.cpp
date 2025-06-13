#include "EntertainmentCollection.h"
#include "Show.h"
#include <iostream>
using namespace std;

void addShow(EntertainmentCollection<Show>& collection) {
    string title, description;
    cout << "Name of Show: ";
    cin.ignore();
    getline(cin, title);
    cout << "Description of Show: ";
    getline(cin, description);
    Show newShow(title, description);

    try {
        collection.add(newShow);
    } catch (const FullCollection& e) {
        cout << e.what() << endl;
    }
}

void removeShow(EntertainmentCollection<Show>& collection) {
    try {
        Show removedShow = collection.remove();
        cout << "The details of the removed show: ";
        removedShow.details();
    } catch (const EmptyCollection& e) {
        cout << e.what() << endl;
    }
}

void displayMenu() {
    cout << "Press 1 to add a show to the collection." << endl;
    cout << "Press 2 to remove a show from the collection." << endl;
    cout << "Press 3 to see how many shows are in the collection." << endl;
    cout << "Press 4 to quit." << endl;
}

int main() {
    EntertainmentCollection<Show> collection;
    char choice;

    do {
        displayMenu();
        int option;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                addShow(collection);
            break;
            case 2:
                removeShow(collection);
            break;
            case 3:
                cout << "The number of shows in shelf: " << collection.numInCollection() << endl;
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
