#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "ItemToPurchase.h"
#include "ShoppingCart.h"


// print out the menu
void PrintMenu() {
    // output all the menu options
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

// take in a char and execute the option corresponding to said char via switch statements
void ExecuteMenu(char option, ShoppingCart& theCart) {
    // switch to go through each option
    // (look at PrintMenu to see what each case entails)
    switch(option) {
        case 'a': {
            // initialize parameters
            string name;
            string description;
            int price;
            int quantity;

            cin.ignore();
            // prompt user for item name, description, price and quantity
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            cin >> price;
            cout << "Enter the item quantity:" << endl;
            cin >> quantity;

            // create a new ItemToPurchase object
            ItemToPurchase item(name, description, price, quantity);

            // add ItemToPurchase object to ShoppingCart
            theCart.AddItem(item);

            cout << endl;
            break;
        }
        case 'd': {
            // initialize parameter
            string inputName;

            cin.ignore();
            // prompt user to remove item from cart
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, inputName);
            theCart.RemoveItem(inputName);
            cout << endl;
            break;
        }
        case 'c': {
            // initialize parameters
            string name;
            int quantity;

            cin.ignore();
            // prompt user for item name and quantity to change the quantity of items
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the new quantity:" << endl;
            cin >> quantity;

            // create a new ItemToPurchase object with these parameters
            ItemToPurchase item(name, "none", 0, quantity);

            // change quantity
            theCart.ModifyItem(item);
            break;
        }
        case 'i': {
            // call PrintDescriptions
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            theCart.PrintDescriptions();
            break;
        }
        case 'o': {
            // call PrintTotal
            cout << "OUTPUT SHOPPING CART" << endl;
            theCart.PrintTotal();
            break;
        }
        default:
            break;
    }
}

int main() {
    // initalize variables
    string customerName;
    string date;
    char input;

    // prompt user for Customer name and Current Date
    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, date);
    cout << endl;

    // create a ShoppingCart object from user input
    ShoppingCart cart(customerName, date);

    // output the Customer Name and Current Date from user input
    cout << "Customer name: " << cart.GetCustomerName() << endl;
    cout << "Today's date: " << cart.GetDate() << endl << endl;

    // do while loop to keep the menu going
    do{

        // print the menu
        PrintMenu();
        cout << endl;
        do{
            cout << "Choose an option:" << endl;

            // take in user input for the menu choice
            cin >> input;

        }while((input != 'a') && (input != 'o') && (input != 'i') && (input != 'd') && (input != 'c')
               && (input != 'q'));

        //execute menu choice
        ExecuteMenu(input, cart);
    }while((input != 'q'));

    return 0;
}


