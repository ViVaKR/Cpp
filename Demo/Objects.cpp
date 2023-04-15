#include <iostream>

using namespace std;

class StudentKR {
  private:
  public:
    std::string name;
    int age;
    double gpa;

    StudentKR(std::string _name, int _age, double _gpa) {
        name = _name;
        age = _age;
        gpa = _gpa;
    }
};

class CarKR {
  public:
    std::string make;
    std::string model;
    int year;
    std::string color;

    CarKR(std::string _make, std::string _model, int _year, std::string _color) {
        make = _make;
        model = _model;
        year = _year;
        color = _color;
    }
};

class PizzaKR {
  private:
    string tp2;

  public:
    string tp1;

    PizzaKR() {}

    PizzaKR(string tp1) {
        this->tp1 = tp1;
    }
    PizzaKR(string tp1, string tp2) {
        this->tp1 = tp1;
        this->tp2 = tp2;
    }

    string GetTp() {
        return this->tp2;
    }

    ~PizzaKR() {
        std::cout << "PizzaKR -> Good Bye!\n";
    }
};

class Stove {
  private:
    int temperature = 0;

  public:
    int GetTemperature() {
        return temperature;
    }

    Stove(int _temperature) {
        SetTemperature(_temperature);
    }

    void SetTemperature(int value) {
        if (value < 0) {
            temperature = 0;
        } else if (value > 10) {
            temperature = 10;
        } else {
            temperature = value;
        }
    }
};

/// @brief Ref. Bro Code
void Objects() {

    // Object
    // A collection of attributes and methods
    // They can have characteristics and could peform actions
    // Can be used to mimic real wordl items (ex. Phone, Book, Dog)
    // Created from a class which acts as a "blud-print"

    // 생성자, Getter and Setter
    StudentKR student("Viv", 23, 3.2);
    std::cout << student.name << endl;
    std::cout << student.age << endl;
    std::cout << student.gpa << endl;

    CarKR car("Chevy", "Corvette", 2022, "red");
    cout << car.make << endl;
    cout << car.color << endl;

    PizzaKR pizza("Pepper");
    PizzaKR pz2("Mushrooms", "Peppers");

    cout << pz2.GetTp() << endl;

    PizzaKR piz;
    piz.tp1 = "GimChiPizza";
    cout << piz.tp1 << endl;

    // Getter and Setter
    // Abstraction : Hiding Unnecessary data from outside a class
    // Getter : Function that makes a private attribute READABLE
    // Setter : Function that makes a private attribute WRITEABLE
    Stove stove(7);
    std::cout << "The temperature setting is: " << stove.GetTemperature() << endl;
    stove.SetTemperature(-100);
    std::cout << "The temperature setting is: " << stove.GetTemperature() << endl;
    stove.SetTemperature(100);
    std::cout << "The temperature setting is: " << stove.GetTemperature() << endl;
    stove.SetTemperature(5);
    std::cout << "The temperature setting is: " << stove.GetTemperature() << endl;

    // Inheritance
    // A clas can recieve attributes and methods form another class
    // Children Classes inherit from a Parent class
    // Helps to reuse similar code found ithin multiple classes
}
