#ifndef ENTERTAINMENT_COLLECTION_H
#define ENTERTAINMENT_COLLECTION_H

#include <iostream>

const int MAX_ITEMS = 10;

class FullCollection : public std::exception {
public:
    const char* what() const noexcept override {
        return "The collection is full, cannot add more items.";
    }
};

class EmptyCollection : public std::exception {
public:
    const char* what() const noexcept override {
        return "The collection is empty, cannot remove items.";
    }
};

template <typename T>
class EntertainmentCollection {
public:
    EntertainmentCollection() : currentCount(0) {}

    void add(const T& item) {
        if (currentCount >= MAX_ITEMS) throw FullCollection();
        items[currentCount++] = item;
    }

    T remove() {
        if (currentCount <= 0) throw EmptyCollection();
        return items[--currentCount];
    }

    int numInCollection() const { return currentCount; }

private:
    T items[MAX_ITEMS];
    int currentCount;
};

#endif
