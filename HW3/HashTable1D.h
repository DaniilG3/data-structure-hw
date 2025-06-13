#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H
#include <vector>

using namespace std;

class HashTable1D {
private:
    vector<int> table;
    int size;

public:
    HashTable1D(int size);
    int insert(int value);
    int search(int value);
    int remove(int value);
    void print();
};

#endif