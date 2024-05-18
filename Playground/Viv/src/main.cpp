#include "../include/TestTemp.hpp"
#include "../include/Utils.hpp"
#include "../include/io.hpp"
#include "Mathematics.cpp"
#include "Student.cpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include <unistd.h>
#include <vector>
#define GetCurrentDir getcwd

using namespace std;
namespace fs = std::filesystem;
void Menu();

string Space(int n)
{
    return string(n, (char)0x20);
}
int main(int argc, char const *argv[])
{

    auto choice(0);
    if (argc >= 2) choice = atoi(argv[1]);

    while (true) {
        system("clear");
        switch (choice) {
            case 0: exit(0);
            case 1: {
                cout << "Array" << endl;
                std::array<int, 5> arr = {1, 2, 3, 4, 5};
                for (size_t i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";
                auto x = {1, 2, 3, 4, 5};

                for (auto &i : x) {
                    cout << i << " ";
                }
                cout << "\n";
                vector<int> v = {1, 2, 3, 4, 5};
                auto it = find(v.begin(), v.end(), 3);
                cout << *it << endl;
            } break;

            case 2: {
                fs::path root = fs::current_path();
                fs::path include("include");
                fs::path io("io.hpp");
                auto file = root / include / io;
                ReadWrite rw(1, file);
                rw.GetPath();
                rw.ReadFile();
                rw.WriteFile();
            } break;

            case 3: {

                std::array<char, 1024> buffer;
                GetCurrentDir(buffer.data(), buffer.size());
                if (!GetCurrentDir(buffer.data(), buffer.size())) {
                    return errno;
                }
                cout << "Current working directory: " << buffer.data() << endl;

                auto path = fs::current_path(); // getting path
                cout << "--> Path: " << path.string() << endl;
            } break;
            case 4: {
                double a = 3.141592;
                double b = 20.0123;
                Utils<double> utils(a, b);
                utils.Print();
                cout << a << " + " << b << " = " << utils.Add() << endl;
            } break;
            case 5: {

                TestTemp<int> test;
                test.SetValue(12345);
                int value = test.GetValue();
                cout << value << endl;

                TestTemp<string> test2;
                test2.SetValue("Hello");
                string value2 = test2.GetValue();
                cout << value2 << endl;
            } break; // [ Template Class 2 ]
            case 6: {

                Student s1(1, "Kim Bum Jun", "용마 초등학교");
                cout << s1.GetId() << " " << s1.GetName() << " " << s1.GetSchool() << endl;
                Student s2(2, "Jang Gil San", "건국 중학교");
                cout << s2.GetId() << " " << s2.GetName() << " " << s2.GetSchool() << endl;

            } break; // [ Inheritance ]
            case 7: {

                int a = 7;
                int b = 9;
                int aa = 11;
                int bb = 12;
                OperatorOverloading c(a, b);
                OperatorOverloading d(aa, bb);

                auto e = c == d ? "Equal" : "Not Equal";
                cout << a << Space(2) << b << Space(2) << "is" << Space(2) << e << endl;

                auto f = c + d;
                cout
                    << f.x
                    << Space(2)
                    << f.y
                    << endl;
                auto pp = ++c;
                cout << "(10, 20)++" << Space(4) << pp.x << Space(4) << pp.y << endl;

                int x = 13;
                int y = 14;
                int z = 5;
                int w = 6;
                OperatorOverloading g(x, y);
                OperatorOverloading h(z, w);
                auto mod = g % h;
                cout << "d % c" << Space(4) << mod.x << Space(4) << mod.y << endl;

            } break; // [ Operator Overloading ]

            default:
                exit(UINT8_MAX);
                break;
        }
        cin.get();
        cout << endl
             << endl
             << "\u2728 \033[33m실행 메뉴 선택\033[0m \u2728"
             << "\n";
        Menu();
        cout << "\n";
        cout << "\033[33m\u269E Enter your choice \u269F\033[0m"
             << endl
             << "\033[31m\u2771\033[0m ";
        cin >> choice;
    }

    return 0;
}

void Menu()
{
    cout << "0. Exit" << endl;
    cout << "1. Array" << endl;
    cout << "10. Array" << endl;
    cout << "11. New Initialize" << endl;
    cout << "12. FloatToBinary" << endl;
    cout << "13. 표준편차" << endl;
    cout << "14. 람다식" << endl;
    cout << "15. 연산자 오버로딩" << endl;
}
