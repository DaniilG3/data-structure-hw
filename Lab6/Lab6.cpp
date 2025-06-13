#include <iostream>
#include "Item.h"
#include "OrderedList.h"

int main() {
    OrderedList<Item> list;

    while (true) {
        std::cout << "Menu (Press 1 - 8):" << std::endl;
        std::cout << "1. Add an item" << std::endl;
        std::cout << "2. Get an item" << std::endl;
        std::cout << "3. Check if the list is empty" << std::endl;
        std::cout << "4. Get the size of the list" << std::endl;
        std::cout << "5. See an item at a location" << std::endl;
        std::cout << "6. See the next item" << std::endl;
        std::cout << "7. See the previous item" << std::endl;
        std::cout << "8. Reset the current location" << std::endl;
        std::cout << "0. Quit\n" << std::endl;

        int choice;
        std::cout << "Enter your choice: "; //choice
        std::cin >> choice;

        if (choice == 0) {
            break; //exit program
        }

        switch (choice) {
        case 1: {
            int sku;
            std::string description; //add an item
            double price;
            std::string uom;
            int quantityOnHand;

            std::cout << "Enter SKU: ";
            std::cin >> sku;
            std::cin.ignore();

            std::cout << "Enter Description: ";
            std::getline(std::cin, description);

            std::cout << "Enter Price: ";
            std::cin >> price;

            std::cout << "Enter UOM: ";
            std::cin >> uom;

            std::cout << "Enter QuantityOnHand (optional, press Enter to skip): ";
            std::cin >> quantityOnHand;

            Item* newItem = new Item(sku, description, price, uom, quantityOnHand);
            list.addItem(newItem);
            break;
        }
        case 2: {
            int sku;
            std::cout << "Enter SKU to search for: "; //take an item off the list
            std::cin >> sku;

            Item itemToFind(sku, "", 0.0, "");
            Item* foundItem = list.getItem(&itemToFind);

            if (foundItem != nullptr) {
                std::cout << "Item found: " << foundItem->getInfo() << std::endl;
            }
            else {
                std::cout << "Item not found.\n" << std::endl;
            }
            break;
        }

        case 3: {
            bool isEmpty = list.isEmpty();

            if (isEmpty) {
                std::cout << "The list is empty." << std::endl; //is the list empty
            }
            else {
                std::cout << "The list is not empty." << std::endl;
            }
            break;
        }
        case 4: {
            int size = list.getSize();
            std::cout << "Size of the list: " << size << std::endl;
            break;
        }
        case 5: {
            int index;
            std::cout << "Enter the index of the item to see: "; //see whats in the list
            std::cin >> index;

            Item* item = list.seeAt(index);

            if (item != nullptr) {
                std::cout << "Item at index " << index << ": " << item->getInfo() << std::endl;
            }
            else {
                std::cout << "Item not found at index " << index << "." << std::endl;
            }
            break;
        }
        case 6: {
            Item* nextItem = list.seeNext();

            if (nextItem != nullptr) {
                std::cout << "Next item: " << nextItem->getInfo() << std::endl;
            }
            else {
                std::cout << "End of the list reached." << std::endl; //end list reached
            }
            break;
        }
        case 7: {
            Item* prevItem = list.seePrev();

            if (prevItem != nullptr) {
                std::cout << "Previous item: " << prevItem->getInfo() << std::endl;
            }
            else {
                std::cout << "Beginning of the list reached." << std::endl; //beginning list reached
            }
            break;
        }
        case 8: {
            list.reset();
            std::cout << "Current location reset to the beginning of the list." << std::endl; //reset your view position within the list
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
