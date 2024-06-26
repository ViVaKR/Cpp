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

    // ~PizzaKR() {
    //     std::cout << "PizzaKR -> Good Bye!\n";
    // }
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

// Parent class
class Animal {
  public:
    bool alive = true;

    void Eat() {
        std::cout << "This animal is eating" << std::endl;
    }
};

class Dog : public Animal {
  private:
  public:
    void Bark() {
        std::cout << "The dog goes woof!" << std::endl;
    }
};

class Cat : public Animal {
  private:
    bool alive = true;

  public:
    void Meow() {
        std::cout << "The cat goes meow!" << std::endl;
    }
};

class Shape {
  public:
    double area;
    double volume;
    Shape() {}
    Shape(double _area, double _volume) {
        area = _area;
        volume = _volume;
    }
};

class Cubes : public Shape {
  public:
    double side;
    Cubes() {}
    Cubes(double _side) {
        this->side = _side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }
};

class Sphere : public Shape {
  public:
    double radius;
    Sphere() {}
    Sphere(double _radius) {
        radius = _radius;
        this->area = 4 * 3.14159 * (radius * radius);
        this->volume = (4 / 3.0) * 3.14159 * (radius * radius * radius);
    }
};

/// @brief
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
    std::cout << endl;
    std::cout << "== 상속 ==" << std::endl;
    Dog dog;
    cout << dog.alive << endl;
    dog.Eat();
    dog.Bark();
    std::cout << endl;

    Sphere sphere(20.0);
    std::cout << "Area: " << sphere.area << " cm/n" << endl;
    std::cout << "Volume: " << sphere.volume << endl;

    Cubes cbb(12.3);
    std::cout << "Area: " << cbb.area << " cm/n" << endl;
    std::cout << "Volume: " << cbb.volume << " cm/n" << endl;
}
