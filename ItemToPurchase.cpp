#include <string>
#include "ItemToPurchase.h"

// constructors
// default
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

// setters
void ItemToPurchase::SetName(string inputName) {
    itemName = inputName;
}

void ItemToPurchase::SetDescription(string inputDes) {
    itemDescription = inputDes;
}


void ItemToPurchase::SetPrice(int inputPrice) {
    itemPrice = inputPrice;
}

void ItemToPurchase::SetQuantity(int inputQuantity) {
    itemQuantity = inputQuantity;
}

// getters
string ItemToPurchase::GetName() {
    return itemName;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}


// other methods
// Outputs the item name followed by the quantity, price, and subtotal
void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemPrice * itemQuantity) << endl;
}

// Outputs the item name and description
void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}