#include "Person.cpp"

#include <iostream>
class Student : private Person
{
  private:
    string School;

  public:
    Student(int id, string name, string school) : Person(id, name), School(school) {}

    void SetSchool(string school)
    {
        School = school;
        cout << "Setting school to " << School << endl;
    }
    string GetSchool()
    {
        return School;
    }
    void SetId(int id)
    {
        Person::SetId(id);
    }
    int GetId()
    {
        return Person::GetId();
    }
    void SetName(string name)
    {
        Person::SetName(name);
    }
    string GetName()
    {
        return Person::GetName();
    }
    ~Student()
    {
        cout << this->GetSchool() << ", Student destructor" << endl;
    }
};
