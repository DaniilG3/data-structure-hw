#include "HashTable1D.h"
#include <iostream>

using namespace std;

// Constructor: Initializes the hash table with the given size and sets all slots to -1 (empty)
HashTable1D::HashTable1D(int size) : size(size), table(size, -1) {}

// Insert a value into the hash table using linear probing
int HashTable1D::insert(int value) {
    int index = value % size; // Calculate the hash index
    int spotsChecked = 0;     // Track the number of spots checked

    // Linear probing: Find the next available slot
    while (table[index] != -1 && spotsChecked < size) {
        index = (index + 1) % size; // Move to the next slot (circular array)
        spotsChecked++;
    }

    // If the table is full, insertion fails
    if (spotsChecked == size) {
        cout << "The value " << value << " cannot be inserted.\n";
        return spotsChecked;
    }

    // Insert the value into the found slot
    table[index] = value;
    return spotsChecked + 1; // Return the total spots checked
}

// Search for a value in the hash table
int HashTable1D::search(int value) {
    int index = value % size; // Calculate the hash index
    int spotsChecked = 0;     // Track the number of spots checked

    // Linear probing: Look for the value or find an empty slot
    while (table[index] != value && table[index] != -1 && spotsChecked < size) {
        index = (index + 1) % size; // Move to the next slot
        spotsChecked++;
    }

    // If the value is found
    if (table[index] == value) {
        cout << "The value " << value << " can be found.\n";
        return spotsChecked + 1; // Return the total spots checked
    }
    else {
        // If the value is not found
        cout << "The value " << value << " cannot be found.\n";
        return spotsChecked;
    }
}

// Remove a value from the hash table
int HashTable1D::remove(int value) {
    int index = value % size; // Calculate the hash index
    int spotsChecked = 0;     // Track the number of spots checked

    // Linear probing: Look for the value or find an empty slot
    while (table[index] != value && table[index] != -1 && spotsChecked < size) {
        index = (index + 1) % size; // Move to the next slot
        spotsChecked++;
    }

    // If the value is found
    if (table[index] == value) {
        table[index] = -1; // Remove the value by setting the slot to -1 (empty)
        cout << "The value " << value << " was removed.\n";
        return spotsChecked + 1;
    }
    else {
        // If the value is not found
        cout << "The value " << value << " cannot be removed.\n";
        return spotsChecked;
    }
}

// Print the current state of the hash table
void HashTable1D::print() {
    for (int i = 0; i < size; ++i) {
        // Show whether the slot is empty or contains a value
        if (table[i] == -1)
            cout << "Slot " << i << ": empty\n";
        else
            cout << "Slot " << i << ": " << table[i] << "\n";
    }
}