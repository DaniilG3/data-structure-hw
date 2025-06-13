#include "HashTable2D.h"
#include <iostream>

using namespace std;

// Constructor: Initializes the hash table with the given dimensions and sets all slots to -1 (empty)
HashTable2D::HashTable2D(int primarySize, int secondarySize)
    : primarySize(primarySize), secondarySize(secondarySize) {
    table.resize(primarySize, vector<int>(secondarySize, -1)); // Resize the table
}

// Insert a value into the hash table
int HashTable2D::insert(int value) {
    int index = value % primarySize; // Calculate the hash index
    int spotsChecked = 0;           // Track the number of spots checked

    // Try to insert the value into an available secondary slot
    for (int i = 0; i < secondarySize; ++i) {
        if (table[index][i] == -1) { // Check if the slot is empty
            table[index][i] = value; // Insert the value
            return spotsChecked + 1; // Return the total spots checked
        }
        spotsChecked++;
    }

    // If all secondary slots are full
    cout << "The value " << value << " cannot be inserted.\n";
    return spotsChecked;
}

// Search for a value in the hash table
int HashTable2D::search(int value) {
    int index = value % primarySize; // Calculate the hash index
    int spotsChecked = 0;           // Track the number of spots checked

    // Look for the value in the secondary slots
    for (int i = 0; i < secondarySize; ++i) {
        if (table[index][i] == value) { // If the value is found
            cout << "The value " << value << " can be found.\n";
            return spotsChecked + 1; // Return the total spots checked
        }
        spotsChecked++;
    }

    // If the value is not found
    cout << "The value " << value << " cannot be found.\n";
    return spotsChecked;
}

// Remove a value from the hash table
int HashTable2D::remove(int value) {
    int index = value % primarySize; // Calculate the hash index
    int spotsChecked = 0;           // Track the number of spots checked

    // Look for the value in the secondary slots
    for (int i = 0; i < secondarySize; ++i) {
        if (table[index][i] == value) { // If the value is found
            table[index][i] = -1;       // Remove the value by setting the slot to -1 (empty)
            cout << "The value " << value << " was removed.\n";
            return spotsChecked + 1;
        }
        spotsChecked++;
    }

    // If the value is not found
    cout << "The value " << value << " cannot be removed.\n";
    return spotsChecked;
}

// Print the current state of the hash table
void HashTable2D::print() {
    for (int i = 0; i < primarySize; ++i) {
        cout << "Slot " << i << ": ";
        for (int j = 0; j < secondarySize; ++j) {
            // Show whether the slot is empty or contains a value
            if (table[i][j] == -1)
                cout << "empty ";
            else
                cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}