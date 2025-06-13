#ifndef DECK_H
#define DECK_H

#include <list>

class Deck {
private:
    struct Card {
        Card* prev;
        Card* next;
        int value;
    };
    int deckSize;
    Card* head;
    Card* tail;

public:
    Deck();
    void enqueue(int value);
    int dequeue();
    int count() const;
};

#endif