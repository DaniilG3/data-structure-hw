#include "SidePile.h"

void SidePile::push(int card) {
    if (cards.size() < max_size) {
        cards.push(card);
    }
}

int SidePile::pop() {
    if (cards.empty()) {
        return -1;
    }
    int card = cards.top();
    cards.pop();
    return card;
}

int SidePile::count() const {
    return cards.size();
}