#include "Movie.h"
#include <iostream>

Movie::Movie(std::string title, std::string description, std::string openingCredits)
: Show(title, description), openingCredits(openingCredits) {}

std::string Movie::getOpeningCredits() {
    return openingCredits;
}

void Movie::setOpeningCredits(std::string openingCredits) {
    this->openingCredits = openingCredits;
}

void Movie::play() {
    std::cout << "Playing: " << openingCredits << std::endl;
}

void Movie::details() {
    std::cout << getTitle() << " - " << getDescription() << " - " << openingCredits << std::endl;
}

