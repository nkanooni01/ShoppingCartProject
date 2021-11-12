/*
 * This class
 */

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
    // constructors
    ShoppingCart();
    ShoppingCart(string name, string date);

    // getters
    string GetCustomerName();
    string GetDate();
    int GetNumItemsInCart();
    int GetCostOfCart();

    // other methods
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);
    void PrintTotal();
    void PrintDescriptions();


private:
    // data members
    string customerName;
    string currentDate;
    vector < ItemToPurchase > cartItems;
};


#endif
