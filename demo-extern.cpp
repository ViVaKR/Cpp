#include <iostream>
#include <cstring>

using namespace std;

extern "C" {
    int demo(int arg1, char* arg2){
        
        for (size_t i = 0; i < arg1; i++)
        {
            cout << arg2 << endl;
        }
        return arg1 + strlen(arg2);
    }
}

// g++-12 -shared -o bin/demo.dylib demo.cpp
