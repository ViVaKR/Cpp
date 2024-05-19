#include "../include/TestTemp.hpp"
#include "../include/Utils.hpp"
#include "../include/io.hpp"
#include "Mathematics.cpp"
#include "Student.cpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <codecvt>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <locale>
#include <stdio.h>
#include <streambuf>
#include <string>
#include <sys/ioctl.h>
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

void Line()
{
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    auto c = "\u27B0";
    std::vector<string> v(w.ws_col, c);
    for (auto i = 0; i < ((v.size() - 5) / 2); i++) {
        cout << v[i];
    }
}

char Cr()
{
    return (char)0xD;
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
                cout << "\u2728"
                     << "[\033[33m Read file \033[0m ]"
                     << "\u2728"
                     << endl;
                // Read file
                fs::path root = fs::current_path();
                fs::path assets("assets");
                fs::path files("files");
                fs::path file("demo_d.txt");
                auto path = root / assets / files / file;
                ReadWrite rw(1, path);
                rw.GetPath();
                rw.ReadFile();
            } break;

            case 3: {
                std::cout << "\u2728"
                          << "[\033[33m Write file \033[0m ]"
                          << "\u2728"
                          << std::endl;
                // Write file
                fs::path root = fs::current_path();
                fs::path assets("assets");
                fs::path files("files");
                fs::path file("demo_d.txt");
                auto path = root / assets / files / file;
                ReadWrite rw(1, path);
                rw.GetPath();
                rw.WriteFile();

            } break; /* [ Write file ] */

            case 4: {
                fs::path root = fs::current_path();
                fs::path assets("assets");
                fs::path csv("csv");
                auto result = fs::create_directories(root / assets / csv);
                if (result) {
                    cout << "Directory created successfully!" << endl;
                } else {
                    cout << "Directory already exists!" << endl;
                }

            } break; /* [ Make Directory ] */

            case 5: {

                std::array<char, 1024> buffer;
                GetCurrentDir(buffer.data(), buffer.size());
                if (!GetCurrentDir(buffer.data(), buffer.size())) {
                    return errno;
                }
                cout << "Current working directory: " << buffer.data() << endl;

                auto path = fs::current_path(); // getting path
                cout << "--> Path: " << path.string() << endl;
            } break;                            /* [ Get Current Directory ] */

            case 6: {
                double a = 3.141592;
                double b = 20.0123;
                Utils<double> utils(a, b);
                utils.Print();
                cout << a << " + " << b << " = " << utils.Add() << endl;
            } break; /* [ Utils ] */

            case 7: {

                TestTemp<int> test;
                test.SetValue(12345);
                int value = test.GetValue();
                cout << value << endl;

                TestTemp<string> test2;
                test2.SetValue("Hello");
                string value2 = test2.GetValue();
                cout << value2 << endl;
            } break; // [ Template Class ]

            case 8: {

                Student s1(1, "Kim Bum Jun", "용마 초등학교");
                cout << s1.GetId() << " " << s1.GetName() << " " << s1.GetSchool() << endl;
                Student s2(2, "Jang Gil San", "건국 중학교");
                cout << s2.GetId() << " " << s2.GetName() << " " << s2.GetSchool() << endl;

            } break; // [ Inheritance ]

            case 9: {
                std::cout << "\u2728"
                          << "[\033[33m Operator overloading \033[0m ]"
                          << "\u2728"
                          << std::endl;
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

            case 10: {
                cout << "\u2728"
                     << "\033[33m ANSI Color \033[0m"
                     << "\u2728"
                     << std::endl
                     << std::endl;

                /*
                Name            FG  BG
                Black           30  40
                Red             31  41
                Green           32  42
                Yellow          33  43
                Blue            34  44
                Magenta         35  45
                Cyan            36  46
                White           37  47
                Bright Black    90  100
                Bright Red      91  101
                Bright Green    92  102
                Bright Yellow   93  103
                Bright Blue     94  104
                Bright Magenta  95  105
                Bright Cyan     96  106
                Bright White    97  107
                 */
                printf("\n");
                printf("\x1B[31mTexting\033[0m\t\t");
                printf("\x1B[32mTexting\033[0m\t\t");
                printf("\x1B[33mTexting\033[0m\t\t");
                printf("\x1B[34mTexting\033[0m\t\t");
                printf("\x1B[35mTexting\033[0m\n");

                printf("\x1B[36mTexting\033[0m\t\t");
                printf("\x1B[36mTexting\033[0m\t\t");
                printf("\x1B[36mTexting\033[0m\t\t");
                printf("\x1B[37mTexting\033[0m\t\t");
                printf("\x1B[93mTexting\033[0m\n");

                printf("\033[3;42;30mTexting\033[0m\t\t");
                printf("\033[3;43;30mTexting\033[0m\t\t");
                printf("\033[3;44;30mTexting\033[0m\t\t");
                printf("\033[3;104;30mTexting\033[0m\t\t");
                printf("\033[3;100;30mTexting\033[0m\n");

                printf("\033[3;47;35mTexting\033[0m\t\t");
                printf("\033[2;47;35mTexting\033[0m\t\t");
                printf("\033[1;47;35mTexting\033[0m\t\t");
                printf("\t\t");
                printf("\n");
            } break; // [ Ansi Color ]

            case 11: {
                Utils<int> utils(0, 0);
                utils.ToBinary(12);
                cout << "\n";
            } break; // [ Print Binary ]

            default:
                exit(UINT8_MAX);
                break;
        }
        cin.get();

        struct winsize w;
        ioctl(fileno(stdout), TIOCGWINSZ, &w);
        string title = "[ 실행 메뉴 선택 ]";
        cout << "\n";
        cout << Space((w.ws_col - title.size()) / 2)
             << "\u2728 \033[33m"
             << title
             << "\033[0m \u2728"
             << "\n";

        Menu();
        cout << "\n";
        std::fflush(stdout);
        cout << "\n";
        cout << "\033[31m\u269E Enter your choice \u269F\033[0m"
             << endl
             << "\033[31m\u2771\033[0m ";
        cin >> choice;
    }

    return 0;
}

void Menu()
{
    vector<string> menus{
        "Exit",                 // 0. 종료
        "Array",                // 1. 배열
        "Read file",            // 2. 파일 읽기
        "Write file",           // 3. 파일 쓰기
        "Make Directory",       // 4. 디렉토리 생성
        "Get Directory",        // 5. 현재 디렉토리 가져오기
        "Utils",                // 6. 유틸리티, 템플릿
        "TestTemp",             // 7. 템플릿 클래스
        "Inheritance",          // 8. 상속
        "Operator Overloading", // 9. 연산자 오버로딩
        "ANSI Color",           // 10. ANSI 색상
        "Print Binary",         // 11. 이진수 출력
    };
    Line();
    cout << "\n";
    for (auto i = 0; i < menus.size(); i++) {
        auto cr = (i + 1) % 4 == 0 ? "\n" : "";
        string menu = std::format("{:3}. {}", i, menus[i]);
        string menu_line = std::format("{:30}", menu);
        cout << menu_line << cr;
    }
    cout << "\n";
    Line();
}
