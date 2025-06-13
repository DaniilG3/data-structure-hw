#include "Shelf.h"

Shelf::Shelf() : currentCount(0) {}

void Shelf::add(const Show& show) {
    if (currentCount >= MAX_SHOWS) {
        throw FullShelf();
    }
    shows[currentCount++] = show;
}

Show Shelf::remove() {
    if (currentCount <= 0) {
        throw EmptyShelf();
    }
    return shows[--currentCount];
}

int Shelf::numInShelf() const {
    return currentCount;
}
