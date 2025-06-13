#include "Item.h"

Item::Item(int sku, const std::string& description, double price, const std::string& uom, int quantityOnHand)
    : sku(sku), description(description), price(price), uom(uom), quantityOnHand(quantityOnHand) {}

std::string Item::getInfo() const {
    return "SKU - " + std::to_string(sku) + ", " + "Description - " + description;
}

double Item::getPrice() const {
    return price;
}

bool Item::inStock() const {
    return quantityOnHand > 0;
}

bool Item::operator>(Item& item) const {
    return sku > item.sku;
}

bool Item::operator<(Item& item) const {
    return sku < item.sku;
}

bool Item::operator==(Item& item) const {
    return sku == item.sku;
}
