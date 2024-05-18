#include "../include/Ground.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int arr[] = {1, 2, 3};
    std::vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "V:\t" << v.size() << ", V2:\t" << v2.size() << endl;

    for (auto &item : v) {
        cout << item << " ";
    }
    cout << endl;
    for (auto &item : v2) {
        cout << item << " ";
    }
    cout << endl;

    // std::vector<int> v3 = {1, 2, 3, 4, 5};
    // vector<int> temp = {1, 2, 3, 4, 5};

    Ground g(1, 2);

    cout << "Hello, World!" << endl;
    cout << "Ground: " << g.getA() << ", " << g.getB() << endl;

    return 0;
}

//--> clang++ -std=c++23 -Wall `find ./src -type d -exec echo -I '{}' \;` -g DemoA.cpp -o ./build/DemoA
// clang++ `find ./src -type d -exec echo -I'{}' \;` -g DemoA.cpp src/Ground.h src/Ground.cpp -v
// clang++ -std=c++23 -Wall -g DemoA.cpp src/Ground.h src/Ground.cpp -v
// clang++  DemoA.cpp `find ./src -type f -exec echo -I'{}' \;` DemoA.cpp -v
// objdump -S a.out
// --> clang++ -c DemoA.cpp
// --> clang++ -std=c++23 -Wall -g DemoA.cpp src/*.h src/*.cpp -v

// --> (1) clang++ -std=c++23 -Wall -c DemoA.cpp src/*.h src/*.cpp -v
// --> (2) clang++ DemoA.o Ground.o -o DemoRun
