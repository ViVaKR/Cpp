#include <iostream>

using namespace std;

class Person
{
  private:
    int Id;
    string Name;

  public:
    Person(int id, string name) : Id(id), Name(name) {}

    void SetId(int id)
    {
        Id = id;
        cout << "Setting id to " << Id << endl;
    }
    int GetId()
    {
        return Id;
    }
    void SetName(string name)
    {
        Name = name;
        cout << "Setting name to " << Name << endl;
    }
    string GetName()
    {
        return Name;
    }

    ~Person()
    {
        cout << this->Name << ", Person destructor" << endl;
    }
};

/*
--> OOP (Object Oriented Programming) is a programming paradigm that uses "objects" to design applications and computer programs.

1. Abstraction
2. Encapsulation
3. Inheritance
4. Polymorphism

 */
