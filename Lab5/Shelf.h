#ifndef SHELF_H
#define SHELF_H

#include "Show.h"
#include <iostream>

const int MAX_SHOWS = 10;


class FullShelf : public std::exception {
public:
    const char* what() const noexcept override {
        return "The shelf is full, cannot add to the shelf.";
    }
};

class EmptyShelf : public std::exception {
public:
    const char* what() const noexcept override {
        return "The shelf is empty, cannot remove from the shelf.";
    }
};

class Shelf {
public:
    Shelf();

    void add(const Show& show);
    Show remove();
    int numInShelf() const;

private:
    Show shows[MAX_SHOWS];
    int currentCount;
};

#endif
