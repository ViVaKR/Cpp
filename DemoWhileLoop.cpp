#include <iostream>

using namespace std;

void DemoWhileLoop()
{
    cout << "== While Loop Demo == \n";
    string name;
    cin.ignore();
    
    while (name.empty())
    {
        cout << "Enter your name : ";
        getline(cin, name);
        cout << endl;
    }
    cout << "Welcome! " << name << endl;
}
