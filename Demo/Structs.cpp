#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Student {
    std::string name;
    int age;
    double gpa;
    bool enrolled = true;
};

struct Car {
    string model;
    int year;
    string color;
};

void PrintCar(Car &car);
void PaintCar(Car &car, string color);

/// @brief Ref: Bro Code
void Structs() {

    // (Struct)
    // A structure that group related vaiable under one name
    // structs can contain many different data types (string, int, double, bool, etc.)
    // variables in a struct are known as "members"
    // members can be access with `.` "Class Member Access Operator"

    Student std1;
    std1.name = "Viv";
    std1.age = 21;
    std1.gpa = 3.2;
    std1.enrolled = true;

    Student std2;
    std2.name = "Hello";
    std2.age = 27;
    std2.gpa = 2.1;

    Student std3;
    std3.name = "World";
    std3.age = 24;
    std3.gpa = 4.1;
    std3.enrolled = true;

    cout << "Name:\t\t" << std1.name << endl;
    cout << "Age:\t\t" << std1.age << endl;
    cout << "Gpa:\t\t" << std1.gpa << endl;
    cout << "Enrolled:\t" << std1.enrolled << endl;
    std::cout << endl;
    cout << "Name:\t\t" << std2.name << endl;
    cout << "Age:\t\t" << std2.age << endl;
    cout << "Gpa:\t\t" << std2.gpa << endl;
    cout << "Enrolled:\t" << std2.enrolled << endl;
    std::cout << endl;
    cout << "Name:\t\t" << std3.name << endl;
    cout << "Age:\t\t" << std3.age << endl;
    cout << "Gpa:\t\t" << std3.gpa << endl;
    cout << "Enrolled:\t" << std3.enrolled << endl;
    std::cout << endl;

    Car car1;
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "red";

    Car car2;
    car2.model = "Corvette";
    car2.year = 2024;
    car2.color = "blue";

    cout << &car1 << endl;

    PaintCar(car1, "silver");
    PaintCar(car2, "red");
    PrintCar(car1);
    PrintCar(car2);
}

void PrintCar(Car &car) { // Pass By References

    cout << &car << endl;
    std::cout << endl;
    cout << car.model << endl;
    cout << car.year << endl;
    cout << car.color << endl;
    std::cout << endl;
}

void PaintCar(Car &car, string color) {
    car.color = color;
}


