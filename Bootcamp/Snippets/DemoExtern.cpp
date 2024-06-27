#include <iostream>
#include <cstring>

using namespace std;

extern "C" {
    int DemoExtern(int arg1, char* arg2){
        
        for (size_t i = 0; i < arg1; i++)
        {
            cout << arg2 << endl;
        }
        return arg1 + strlen(arg2);
    }
}

// 내보네기 스크립트
// g++-12 -shared -o bin/demo.dylib DemoExtern.cpp
