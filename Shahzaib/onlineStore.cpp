#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a struct for items in the store
struct Item {
    string name;
    double price;
};

// Define a class for the online store
class OnlineStore {
private:
    vector<Item> inventory;
    vector<Item> cart;
public:
    // Constructor to initialize the inventory
    OnlineStore() {
        // Add some initial items to the inventory
        inventory.push_back({"Milk", 10.99});
        inventory.push_back({"Rice", 20.49});
        inventory.push_back({"Mango", 5.99});
    }

    // Function to display available items in the store
    void displayInventory() {
        system("cls");
        cout << "Available Items:" << endl;
        for (const auto& item : inventory) {
            cout << item.name << " - $" << item.price << endl;
        }
    }

    // Function to add an item to the cart
    void addToCart(const string& itemName) {
        for (const auto& item : inventory) {
            if (item.name == itemName) {
                cart.push_back(item);
                cout << "Added " << itemName << " to cart." << endl;
                return;
            }
        }
        cout << "Item not found in inventory." << endl;
    }

    // Function to calculate and display the total cost of items in the cart
    void displayCartTotal() {
        double total = 0.0;
        for (const auto& item : cart) {
            total += item.price;
        }
        cout << "Total Cost: $" << total << endl;
    }
};

int main() {
    // Create an instance of the OnlineStore class
    OnlineStore store;

    // Display available items in the store
    store.displayInventory();

    // Add items to the cart
    cout<<endl;
    store.addToCart("Milk");
    store.addToCart("Mango");
    cout<<endl;

    // Display the total cost of items in the cart.
    store.displayCartTotal();

    return 0;
}
