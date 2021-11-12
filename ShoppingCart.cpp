#include <string>
#include <vector>
#include "ShoppingCart.h"

// constructors
// default
ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

// getters
string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

// Returns quantity of all items in cart.
int ShoppingCart::GetNumItemsInCart() {
    // initalize parameters
    int itemInCart = cartItems.size();
    int totalQuantity = 0;

    // check if cartItems is empty or not. If empty, return 0
    if(itemInCart > 0) {
        // for loop to go through cartItems
        for(int i = 0; i < itemInCart; i++) {
            // add up all the quantities
            totalQuantity += cartItems.at(i).GetQuantity();
        }
    }

    // return the total quantity
    return totalQuantity;

}

// Determines and returns the total cost of items in cart. Has no parameters
int ShoppingCart::GetCostOfCart() {
    // initalize parameters
    int itemInCart = cartItems.size();
    int totalCost = 0;
    int itemCost;

    // check if cartItems is empty or not. If empty, return 0
    if(itemInCart > 0) {
        // for loop to go through cartItems
        for(int i = 0; i < itemInCart; i++) {

            // add up all the costs
            itemCost = (cartItems.at(i).GetPrice()) * (cartItems.at(i).GetQuantity());
            totalCost += itemCost;
        }

    }

    // return the total cost
    return totalCost;
}

// other methods
// Adds an item to cartItems vector.
void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

// Removes item from cartItems vector.
// If item name cannot be found, a message will be outputted
void ShoppingCart::RemoveItem(string itemName) {
    // initialize variables
    int itemInCart = cartItems.size();
    string cartItemName;
    int itemAmount = 0;

    // If there's no elements in vector, output a message
    if(itemInCart > 0) {
        // for loop to check each cartItem
        for(int i = 0; i < itemInCart; i++) {
            cartItemName = cartItems.at(i).GetName();
            // if true, remove the item from vector
            if(cartItemName == itemName) {
                cartItems.erase(cartItems.begin() + i);
                // decrease i by 1 to continue the loop
                i--;
                itemInCart--;
                itemAmount++;
            }
        }

        // If item name cannot be found, a message will be outputted
        if(itemAmount == 0) {
            cout << "Item not found in cart. Nothing removed." << endl << endl;
        }
    }else{
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }
}

// Modifies an item's description, price, and/or quantity.
void ShoppingCart::ModifyItem(ItemToPurchase item) {
    // initialize variables
    int itemInCart = cartItems.size();
    bool itemNameIsPresent = false;

    // If there's no elements in vector, output a message
    if(itemInCart > 0) {
        // for loop to check each cartItem
        for(int i = 0; i < itemInCart; i++) {
            // set quantity to current ItemToPurchase quantity
            if(cartItems.at(i).GetName() == item.GetName()) {
                // set the itm in the cartItem vector's quantity to the input quantity
                // break right after to end the loop.
                cartItems.at(i).SetQuantity(item.GetQuantity());
                itemNameIsPresent = true;
                break;
            }
        }

        // if name of item isn't present in vector, output a message
        if(itemNameIsPresent == false) {
            cout << "Item not found in cart. Nothing modified." << endl << endl;
        }

    }else{
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

// Outputs total of objects in cart.
void ShoppingCart::PrintTotal() {
    // initialize variable
    int itemInCart = cartItems.size();

    // print out shopping cart and number of items
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    // for loop to go through cartItems
    if(itemInCart > 0) {
        for (int i = 0; i < itemInCart; i++) {
            // print out ItemToPurchase cost
            cartItems.at(i).PrintItemCost();
        }
    }else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl;

    // print out the total cost of cart
    cout << "Total: $" << GetCostOfCart() << endl << endl;

}

// Outputs each item's description
void ShoppingCart::PrintDescriptions() {
    // initialize variables
    int itemsInCart = cartItems.size();

    // print out shopping cart and number of items
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    // for loop to go through cartItems
    for(int i = 0; i < itemsInCart; i++) {
        // print out ItemToPurchase descriptions
        cartItems.at(i).PrintItemDescription();
    }

    cout << endl;
}



