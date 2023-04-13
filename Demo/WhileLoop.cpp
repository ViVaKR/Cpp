#include <iostream>

using namespace std;

void WhileLoop()
{
    cout << "== While Loop Demo == \n";
    string name;
    cout << "Enter Your Name >>> ";
    cin.ignore();
    
    while (name.empty())
    {
        cout << "Enter your name : ";
        getline(cin, name);
        cout << endl;
    }
    cout << "Welcome! " << name << endl;
}
