#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H
#include <vector>

using namespace std;

class HashTable2D {
private:
    vector<vector<int>> table;
    int primarySize;
    int secondarySize;

public:
    HashTable2D(int primarySize, int secondarySize);
    int insert(int value);
    int search(int value);
    int remove(int value);
    void print();
};

#endif