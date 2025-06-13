#include "WordCount.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <cctype>  // For tolower()

// Main function
int main() {
    BinarySearchTree<WordCount> bst;
    std::string word;

    // Prompt the user for their choice: I, F, S, D, P, or Q.
    while (true) {
        std::cout << "\nMenu Options:" << std::endl;
        std::cout << "I - Insert a word" << std::endl;
        std::cout << "F - Find a word" << std::endl;
        std::cout << "S - Get the size of the tree" << std::endl;
        std::cout << "D - Delete a word" << std::endl;
        std::cout << "P - Display the tree" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter your choice: ";

        char command;
        std::cin >> command;

        // Convert the command to lowercase to handle input case-insensitively
        command = tolower(command);

        if (command == 'i') {
            std::cout << "Enter a word to insert: ";
            std::cin >> word;
            WordCount* value = new WordCount(word);
            WordCount* foundWordCount = bst.insert(value);
            std::cout << "word: " << foundWordCount->getWord()
                << " - count: " << foundWordCount->getCount() << std::endl;

        }
        else if (command == 'f') {
            std::cout << "Enter a word to find: ";
            std::cin >> word;
            WordCount* value = new WordCount(word);
            WordCount* foundWordCount = bst.find(value);

            if (foundWordCount) {
                std::cout << "word: " << foundWordCount->getWord()
                    << " - count: " << foundWordCount->getCount() << std::endl;
            }
            else {
                std::cout << "Word not found in the tree." << std::endl;
            }

            delete value;  // Clean up dynamically allocated memory
        }
        else if (command == 's') {
            std::cout << "The size of the tree: " << bst.getSize() << std::endl;
        }
        else if (command == 'd') {
            std::cout << "Enter a word to delete: ";
            std::cin >> word;
            WordCount* value = new WordCount(word);
            WordCount* deletedWordCount = bst.deleteNode(value);

            if (deletedWordCount) {
                std::cout << "Deleted word: " << deletedWordCount->getWord()
                    << " - count: " << deletedWordCount->getCount() << std::endl;
                delete deletedWordCount;  // Clean up deleted node's memory
            }
            else {
                std::cout << "Word not found in the tree." << std::endl;
            }

            delete value;  // Clean up dynamically allocated memory
        }
        else if (command == 'p') {
            std::cout << "Displaying the tree in order:" << std::endl;
            bst.displayInOrder();
        }
        else if (command == 'q') {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
