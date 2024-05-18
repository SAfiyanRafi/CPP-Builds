#include <iostream>
#include <string>
using namespace std;
int main() 
{
    string str;
    string oldSubstr;
    string newSubstr;
    size_t pos;

    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter the substring to replace: ";
    getline(cin, oldSubstr);
    cout << "Enter the replacement substring: ";
    getline(cin, newSubstr);
     pos = str.find(oldSubstr);
    if (pos != string::npos) {
        str.replace(pos, oldSubstr.length(), newSubstr);
        cout << "After replacement: " << str << endl;
    } else 
    {
        cout << "Substring not found in the input string." << ::endl;
    }
    return 0;
}
