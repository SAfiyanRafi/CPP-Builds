#include <iostream>
#include <conio.h>
using namespace std;;
class sys
{
private:
//---------------------------------------
//       Login Data
//---------------------------------------
string mainUserName,mainUserPass;
string adminName = "asdf";
string adminPass = "asdf";
//---------------------------------------
//       Store Data
//---------------------------------------
string stock[2];

double product_quantity[2];

double product_price[2];
//---------------------------------------
//       Admin Controls
//---------------------------------------
void stockEntry()
{

    system("cls");
    for (int i = 0; i < 2; i++)
    {
        string name;
        double quan,pric;
        cout<<"Enter Product Name: ";
        cin>>name;
        stock[i] = name;
        cout<<"Enter Product"<<i+1<< "quantity: ";
        cin>>quan;
        product_quantity[i] = quan;
        cout<<"Enter Product Price: $";
        cin>>pric;
        product_price[i] = pric;
        cout<<endl;
    }
    adminMenu();
}
void displayStock()
{
    system("cls");
    for (int i = 0; i < 2; i++)
    {
        cout<<"Item        "<<"Quantity        "<<"Price"<<endl;
        cout<<stock[i]<<"        "<<product_quantity[i]<<"        "<<"$"<<product_price[i]<<endl;
    }
}

void adminMenu()
{
    system("cls");
    cout<<"1) Data Entry"<<endl;
    cout<<"2) Display Stock"<<endl;
    cout<<"3) Admin Menu"<<endl;

    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
    stockEntry();
    break;

    case 2:
    displayStock();
    break;

    case 3:
    adminMenu();
    break;
    
    default:
    cout<<"Invalid case!!!";
    getch();
    adminMenu();
    break;
    }

}

//---------------------------------------


public:
void adminAuth()
{
    string x,y;
    system("cls");
    cout<<"username: ";
    cin>>x;
    cout<<"Password: ";
    cin>>y;
    
    if (x==adminName && y==adminPass)
    {
        system("cls");
        cout<<"Login Done"<<endl;
        cout<<"Press any to enter Admin Menu"<<endl;
        getch();
        adminMenu();
    }
    else
    {
        cout<<"Username or Password Incorrect"<<endl;
        cout<<"Enter any key to exit: ";
        getch();
        run();
    }
}

void customerAuth()
{
    start();
}

void auth(string &authUser, string &authPwd)
{
    if (authUser==mainUserName && authPwd==mainUserPass)
    {
        system("cls");
        cout<<"Login Done"<<endl;
    }
    else
    {
        system("cls");
        cout<<"Username or Password Incorrect"<<endl;
        cout<<"Enter any key to exit: ";
        getch();
        start();
    }

}

void setID()
{
    system("cls");
    cout<<"Make a username: ";
    cin>>mainUserName;
    cout<<"Enter Password: ";
    cin>>mainUserPass;
    start();
}

void start()
{
    system("cls");
    cout<<"--------------------------------"<<endl;
    cout<<"\t Register/Login"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"   1 : Register"<<endl;
    cout<<"   2 : Login"<<endl;
    cout<<"   3 : Exit"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"Enter Choice: ";

    int choise;
    cin>>choise;
    string x,y;

    switch (choise)
    {
    case 1:
    setID();
    break;

    case 2:
    system("cls");
    cout<<"username: ";
    cin>>x;
    cout<<"Password: ";
    cin>>y;
    auth(x,y);
    break;

    case 3:
    exit(0);
    break;
    default:
    cout<<"Ivalid Entry"<<endl;
    break;
    }
}

void run()
{
    int choice;
    system("cls");
    cout<<"Choose Role:"<<endl;
    cout<<"1) Admin"<<endl;
    cout<<"2) Customer"<<endl;
    cout<<"Enter: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
    adminAuth();
    break;

    case 2:
    customerAuth();
    break;
    
    default:
    cout<<"Invalid case!!!"<<endl;
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