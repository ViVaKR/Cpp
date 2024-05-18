// #include "read.cpp"
// #include "write.cpp"
#include "../include/io.hpp"
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

int main(int argc, char const *argv[])
{

    auto choice(0);
    if (argc >= 2) choice = atoi(argv[1]);

    while (true) {
        //
        switch (choice) {
            case 0: exit(0); break;
            case 1: {
                //
                std::array<int, 5> arr = {1, 2, 3, 4, 5};
                for (size_t i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }

                auto x = {1, 2, 3, 4, 5};

                for (auto &i : x) {
                    cout << i << " ";
                }
                vector<int> v = {1, 2, 3, 4, 5};

                auto it = find(v.begin(), v.end(), 3);
                cout << *it << endl;
                return 1;
            };

            case 2: {
                fs::path root = fs::current_path();
                fs::path include("include");
                fs::path io("io.hpp");
                auto file = root / include / io;
                ReadWrite rw(1, file);
                rw.GetPath();
                rw.ReadFile();
                rw.WriteFile();
                exit(0);
            };

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
            } break;
            case 5: {
            } break;
            case 6: {
            } break;
            case 7: {
            } break;

            default:
                exit(UINT8_MAX);
                break;
        }
    }

    return 0;
}
