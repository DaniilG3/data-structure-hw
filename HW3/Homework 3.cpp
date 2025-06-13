#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include "HashTable1D.h"
#include "HashTable2D.h"

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    // Create two hash tables
    HashTable1D hashTable1D(500);     // 1D hash table with 500 slots
    HashTable2D hashTable2D(100, 5); // 2D hash table with 100 primary slots, each with 5 secondary slots

    // Generate a dataset of 100 unique random integers between 1 and 1000
    int dataset[100];
    for (int i = 0; i < 100; i++) {
        int random = rand() % 1000 + 1;
        dataset[i] = random; // Store the random value in the dataset
    }

    // Initial Insertion: Insert the first 50 values into both hash tables
    int spots1D = 0, spots2D = 0;
    for (int i = 0; i < 50; ++i) {
        spots1D += hashTable1D.insert(dataset[i]); // Insert into 1D hash table
        spots2D += hashTable2D.insert(dataset[i]); // Insert into 2D hash table
    }
    cout << "Initial Insertion - 1D: " << spots1D << ", 2D: " << spots2D << "\n\n";

    // Selective Removal: Remove values divisible by 7
    spots1D = spots2D = 0;
    for (int i = 0; i < 50; ++i) {
        if (dataset[i] % 7 == 0) { // Check if the value is divisible by 7
            spots1D += hashTable1D.remove(dataset[i]); // Remove from 1D hash table
            spots2D += hashTable2D.remove(dataset[i]); // Remove from 2D hash table
        }
    }
    cout << "Selective Removal - 1D: " << spots1D << ", 2D: " << spots2D << "\n\n";

    // Second Insertion: Insert the remaining 50 values into both hash tables
    spots1D = spots2D = 0;
    for (int i = 50; i < 100; ++i) {
        spots1D += hashTable1D.insert(dataset[i]); // Insert into 1D hash table
        spots2D += hashTable2D.insert(dataset[i]); // Insert into 2D hash table
    }
    cout << "Second Insertion - 1D: " << spots1D << ", 2D: " << spots2D << "\n\n";

    // Search Operation: Search for values divisible by 9
    spots1D = spots2D = 0;
    for (const auto& value : dataset) {
        if (value % 9 == 0) { // Check if the value is divisible by 9
            spots1D += hashTable1D.search(value); // Search in 1D hash table
            spots2D += hashTable2D.search(value); // Search in 2D hash table
        }
    }
    cout << "Search Operation - 1D: " << spots1D << ", 2D: " << spots2D << "\n";

    return 0;
}