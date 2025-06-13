#include "Show.h"
#include "Movie.h"
#include <iostream>
#include <string>

void watch(Show& show) {
    show.info();
    show.details();
    show.play();
}

int main() {
    char repeat;
    while (true) {
        int choice;
        std::cout << "Press 1 for creating an instance of Show." << std::endl;
        std::cout << "Press 2 for creating an instance of Movie." << std::endl;
        std::cout << "Press 3 for creating an instance of a Movie declared as a Show." << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        std::string title, description, openingCredits;

        std::cout << "Enter title: ";
        std::getline(std::cin, title);
        std::cout << "Enter description: ";
        std::getline(std::cin, description);

        if (choice == 1) {
            Show show(title, description);
            show.info();
            show.details();
            show.play();
            std::cout << std::endl;
            watch(show);
            std::cout << std::endl;
        } else if (choice == 2) {
            std::cout << "Enter opening credits: ";
            std::getline(std::cin, openingCredits);
            Movie movie(title, description, openingCredits);
            movie.info();
            movie.details();
            movie.play();
            std::cout << std::endl;
            watch(movie);
            std::cout << std::endl;
        } else if (choice == 3) {
            std::cout << "Enter opening credits: ";
            std::getline(std::cin, openingCredits);
            Show* movie = new Movie(title, description, openingCredits);
            movie->info();
            movie->details();
            movie->play();
            std::cout << std::endl;
            watch(*movie);
            std::cout << std::endl;
            delete movie;
        }

        std::cout << "Do you want to continue? [Y/N]: ";
        std::cin >> repeat;
        std::cin.ignore();

        if (repeat != 'Y' && repeat != 'y') {
            break;
        }
    }
    return 0;
}
