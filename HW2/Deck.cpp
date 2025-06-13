#include "Deck.h"

Deck::Deck() {
    tail = nullptr;
    head = nullptr;
    deckSize = 0;
}

void Deck::enqueue(int value) {
    Card* newCard;
    newCard = new Card;
    newCard->value = value;
    deckSize += 1;

    if (head != nullptr) {
        if (!tail) {
            head->next = newCard;
            tail = newCard;
        }
        else {
            Card* prevNode;
            prevNode = tail;
            tail = newCard;
            tail->prev = prevNode;
            prevNode->next = tail;
        }
    }
    else {
        head = newCard;
    }
}

int Deck::dequeue() {
    int valueRet;
    if (head != nullptr) {
        Card* newHead = head->next;
        valueRet = head->value;
        delete head;
        head = newHead;
        deckSize -= 1;
        return valueRet;
    }
}

int Deck::count() const {
    return deckSize;
}