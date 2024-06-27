#include <iostream>

using namespace std;

enum Day { sunday = 0,
           monday,
           tuesday,
           wendnesday,
           thursday,
           friday,
           saturday };

enum Color { red,
             orange,
             yellow,
             green };

void Enums() {
    // enums
    // A User-Defined data type that consists of paired namd-integer constants.
    // GREAT if you have a set of potential options

    cout << "str" << endl;
    Day day = Day::friday;
    switch (day) {
        case friday: cout << "It is friday!" << endl; break;
    }
}
