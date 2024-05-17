#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
using namespace std;

class sys
{
private:
    //---------------------------------------
    //       Login Data
    //---------------------------------------
    string mainUserName = "l";
    string mainUserPass = "l";
    string adminName = "l";
    string adminPass = "l";
    //---------------------------------------
    //       Store Data
    //---------------------------------------
    vector<string> stock_item = {"Milk", "Apples"};
    vector<int> product_quantity = {3, 20};
    vector<double> product_price = {32, 21};
    //---------------------------------------
    //       User Cart
    //---------------------------------------
    vector<string> user_cart_items = {"", ""};
    vector<int> user_item_quantity = {0, 0};
    vector<double> user_item_price = {0, 0};
    int total_cart_items = user_cart_items.size();
    //---------------------------------------
    //       Admin Controls
    //---------------------------------------
    void adminMenu()
    {
        system("cls");
        cout << "1) Display Stock" << endl;
        cout << "2) Edit Stock" << endl; // New option for editing stock
        cout << "3) Add New Product" << endl; // New option for adding stock items
        cout << "4) Exit" << endl;

        int choice;
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayStock();
            break;
        case 2:
            editStock(); // Call the new editStock method
            break;
        case 3:
            addNewStockItem(); // Call the new addNewStockItem method
            break;
        case 4:
            run();
            break;
        default:
            cout << "Invalid choice!!!";
            getch();
            adminMenu();
            break;
        }
    }

    void displayStock()
    {
        system("cls");
        cout << "STOCK ITEMS" << endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "--------------------------------------------------" << endl;
        for (size_t i = 0; i < stock_item.size(); i++)
        {
            cout << setw(5) << left << i + 1 << setw(15) << left << stock_item[i]
                 << setw(15) << left << product_quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << product_price[i] << endl;
        }
        cout << endl;
        cout << "Press any key to return...";
        getch();
        adminMenu();
    }

    void editStock()
    {
        system("cls");

        system("cls");
        cout << "STOCK ITEMS" << endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "--------------------------------------------------" << endl;
        for (size_t i = 0; i < stock_item.size(); i++)
        {
            cout << setw(5) << left << i + 1 << setw(15) << left << stock_item[i]
                 << setw(15) << left << product_quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << product_price[i] << endl;
        }
        cout << endl;
        cout << endl;

        int itemNumber;
        cout << "Enter the number of the item you want to edit: ";
        cin >> itemNumber;

        if (itemNumber < 1 || itemNumber > stock_item.size())
        {
            cout << "Invalid item number!" << endl;
            getch();
            adminMenu();
            return;
        }

        itemNumber -= 1; // Adjust for array index

        string name;
        int quan;
        double pric;

        cout << "Enter new name for " << stock_item[itemNumber] << ": ";
        cin >> name;
        cout << "Enter new quantity: ";
        cin >> quan;
        cout << "Enter new price: $";
        cin >> pric;

        stock_item[itemNumber] = name;
        product_quantity[itemNumber] = quan;
        product_price[itemNumber] = pric;
        cout<<endl;

        cout << "Stock updated successfully!";
        getch();
        adminMenu();
    }

    void addNewStockItem()
    {
        system("cls");
        string name;
        int quan;
        double pric;

        cout << "Enter Product Name: ";
        cin >> name;
        cin.ignore();
        cout << "Quantity: ";
        cin >> quan;
        cin.ignore();
        cout << "Price: $";
        cin >> pric;
        cin.ignore();

        stock_item.push_back(name);
        product_quantity.push_back(quan);
        product_price.push_back(pric);
        cout<<endl;

        cout << "New stock item added successfully...";
        getch();
        adminMenu();
    }

    //---------------------------------------
    //       User Controls
    //---------------------------------------
    void userMenu()
    {
        char choice;

        system("cls");
        cout << "STOCK ITEMS" << endl;   // Display Stock
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "--------------------------------------------------" << endl;
        for (size_t i = 0; i < stock_item.size(); i++)
        {
            cout << setw(5) << left << i + 1 << setw(15) << left << stock_item[i]
                 << setw(15) << left << product_quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << product_price[i] << endl;
        }

        cout << endl;
        cout << endl;  //User Menu
        cout << "1) Add to cart" << endl;
        cout << "2) View Cart" << endl;
        cout << "3) Logout" << endl;
        cout << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cartManipulation();
            break;
        case '2':
            viewCart();
            break;
        case '3':
            run();
            break;
        default:
            cout << "Invalid choice!!!";
            getch();
            userMenu();
            break;
        }
    }

    void cartManipulation()
    {
        char choice;
                system("cls");
        cout << "STOCK ITEMS" << endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "--------------------------------------------------" << endl;
        for (size_t i = 0; i < stock_item.size(); i++)
        {
            cout << setw(5) << left << i + 1 << setw(15) << left << stock_item[i]
                 << setw(15) << left << product_quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << product_price[i] << endl;
        }
        cout << endl;

        do
        {
            cout << "Press E/e to Exit: \n";
            cout << "Choose No: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
                if (product_quantity[0] > 0)
                {
                    user_cart_items[0] = stock_item[0];
                    product_quantity[0] -= 1;
                    user_item_quantity[0] += 1;
                    user_item_price[0] += product_price[0];
                }
                else
                {
                    cout << "No More Left" << endl;
                    getch();
                    cartManipulation();
                }
                break;

            case '2':
                if (product_quantity[1] > 0)
                {
                    user_cart_items[1] = stock_item[1];
                    product_quantity[1] -= 1;
                    user_item_quantity[1] += 1;
                    user_item_price[1] += product_price[1];
                }
                else
                {
                    cout << "No More Left" << endl;
                    getch();
                    cartManipulation();
                }
                break;

            case 'e':
                userMenu();
                break;
            }
        } while (true);
    }

    void viewCart()
    {
        system("cls");
        cout << "CART" << endl;
        cout << endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Cost" << endl;

        for (size_t i = 0; i < total_cart_items; i++)
        {
            cout << setw(5) << left << i + 1 << setw(15) << left << user_cart_items[i]
                 << setw(15) << left << user_item_quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << user_item_price[i] << endl;
        }

        double cart_item_total_price = 0;
        for (size_t i = 0; i < total_cart_items; i++)
        {
            cart_item_total_price += user_item_price[i];
        }

        cout << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << "Total items: " << total_cart_items << endl;
        cout << "Total Checkout price: " << cart_item_total_price << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "Press any key to return to User Menu...";
        getch();
        userMenu();
    }

    //---------------------------------------
public:
    void admin_Auth()
    {
        string x, y;
        system("cls");
        cout << "username: ";
        cin >> x;
        cout << "Password: ";
        cin >> y;

        if (x == adminName && y == adminPass)
        {
            system("cls");
            cout << "Login Done" << endl;
            cout << "Press any key to enter Admin Menu ";
            getch();
            adminMenu();
        }
        else
        {
            cout << "Username or Password Incorrect" << endl;
            cout << "Enter any key to exit: ";
            getch();
            run();
        }
    }

    void user_Auth(string &authUser, string &authPwd)
    {

        if (authUser == mainUserName && authPwd == mainUserPass)
        {
            system("cls");
            cout << "Login Done" << endl;
            cout << "Press any key to view Items...";
            getch();
            userMenu();
        }
        else
        {
            system("cls");
            cout << "Username or Password Incorrect" << endl;
            cout << "Enter any key to exit: ";
            getch();
            user_SignUp_Login_Menu();
        }
    }

    void user_singUp()
    {
        system("cls");
        cout << "Make a username: ";
        cin >> mainUserName;
        cout << "Enter Password: ";
        cin >> mainUserPass;
        user_SignUp_Login_Menu();
    }

    void user_SignUp_Login_Menu()
    {
        system("cls");
        cout << "--------------------------------" << endl;
        cout << "\t Register/Login" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout<<endl;

        string tmp_usr,tmp_pass;
        int choice;
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            user_singUp();
            break;
        case 2:
            system("cls");
            cout<<"Username: ";
            cin>>tmp_usr;
            cout<<"Password: ";
            cin>>tmp_pass;
            user_Auth(tmp_usr, tmp_pass);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice!!!";
            getch();
            user_SignUp_Login_Menu();
            break;
        }
    }

    void run()
    {
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "\tWelcome to Store Management System" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. User Login" << endl;
        cout << "3. Exit" << endl;
        cout<<endl;

        int choice;
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin_Auth();
            break;
        case 2:
            user_SignUp_Login_Menu();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid choice!!!";
            getch();
            run();
            break;
        }
    }
};

int main()
{
    sys store;
    store.run();
    return 0;
}
