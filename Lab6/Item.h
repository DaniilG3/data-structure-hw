#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
private:
    int sku;
    std::string description;
    double price;
    std::string uom;
    int quantityOnHand;

public:
    Item(int sku, const std::string& description, double price, const std::string& uom, int quantityOnHand = 0); //SET IT TO 0
    std::string getInfo() const;
    double getPrice() const;
    bool inStock() const;
    //Overloads operators!!!
    bool operator>(Item& item) const;
    bool operator<(Item& item) const;
    bool operator==(Item& item) const;
};
#endif

