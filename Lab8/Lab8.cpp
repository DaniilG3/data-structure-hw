#include "RedBlackTree.h"

int main() {
    RedBlackTree<int> rbtree;

    while (true) {
        std::cout << "Menu (Press 0 - 5):" << std::endl;
        std::cout << "1. Insert a key" << std::endl;
        std::cout << "2. Remove a key " << std::endl;
        std::cout << "3. Get the subtree key count for a targeted key" << std::endl;
        std::cout << "4. Get tree's nth-largest key" << std::endl;
        std::cout << "5. Output the tree" << std::endl;
        std::cout << "0. Quit\n" << std::endl;

        int choice;
        std::cout << "Enter your choice: "; //choice
        std::cin >> choice;

        if (choice == 0) {
            break; //exit program
        }

        switch (choice) {
        case 1: {
            int key;
            std::cout << "Enter the key to be inserted: ";
            std::cin >> key;
            rbtree.insert(key);
            break;
        }
        case 2: {
            int key;
            std::cout << "Enter the key to be removed: ";
            std::cin >> key;
            rbtree.remove(key);
            break;
        }

        case 3: {
            int key;
            std::cout << "Enter the targeted key: ";
            std::cin >> key;
            int subtreeKeyCount = rbtree.getSubtreeKeyCount(key);
            std::cout << "The subtree key count for " << key << " is: " << subtreeKeyCount << std::endl;
            break;
        }
        case 4: {
            int n;
            std::cout << "Enter number n: ";
            std::cin >> n;
            try {
                std::cout << "The " << n << "-th key is: " << rbtree.GetNthKey(n) << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            rbtree.printTree();
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}