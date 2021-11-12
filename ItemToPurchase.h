#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
#include <iostream>
#include <string>
using namespace std;

class ItemToPurchase {
public:
    // constructors
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    // setters
    void SetName(string inputName);
    void SetDescription(string inputDes);
    void SetPrice(int inputPrice);
    void SetQuantity(int inputQuantity);

    // getters
    string GetName();
    int GetPrice();
    int GetQuantity();
    string GetDescription();

    // other methods
    void PrintItemCost();
    void PrintItemDescription();

private:
    // data members
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif
