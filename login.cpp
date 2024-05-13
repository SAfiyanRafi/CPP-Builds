#include <iostream>
using namespace std;
class sys
{
    private:
    string userName;
    string pass;
public:
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
    switch (choise)
    {
    case 1:
    setID();
    break;
    case 2:
    checkID();
    break;
    case 3:
    exit(0);
    break;
    default:
    cout<<"Ivalid Entry"<<endl;
    break;
    }
}
void setID()
{
    system("cls");
    cout<<"Make a username: ";
    cin>>userName;
    cout<<"Enter Password: ";
    cin>>pass;
    start();
}

void checkID()
{ string name,psw;
    system("cls");
    cout<<"username: ";
    cin>>name;
    cout<<"Password: ";
    cin>>psw;

    if (userName==name && pass==psw)
    {
        system("cls");
        cout<<"Login Done"<<endl;
    }
    else
    {
        system("cls");
        cout<<"Username or Password Incorrect"<<endl;
    }
}

};

int main()
{
    sys obj;
    obj.start();

    return 0;
}