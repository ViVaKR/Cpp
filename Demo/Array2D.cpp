#include <iostream>

using namespace std;

void Array2D() {

    // 2차원 배열 [행][열]
    string cars[][4] = {{"Grandeur", "Sonata", "Accent", "Viv-04"},
                        {"Mustang", "Escape", "F-150", "Viv-14"},
                        {"Corvette", "Equinox", "Silverade", "Viv-24"}};

    int rows = sizeof(cars) / sizeof(cars[0]);
    int columns = sizeof(cars[0]) / sizeof(cars[0][0]);

    cout << "행: " << rows << ", 열: " << columns << endl; 

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            cout << " - " << cars[i][j] << endl;
        }
    }

    cout << cars[0][0] << " ";
    cout << cars[0][1] << " ";
    cout << cars[0][2] << " ";
    cout << cars[0][3] << " ";
    std::cout << endl;
    cout << cars[1][0] << " ";
    cout << cars[1][1] << " ";
    cout << cars[1][2] << " ";
    cout << cars[1][3] << " ";
    std::cout << endl;
    cout << cars[2][0] << " ";
    cout << cars[2][1] << " ";
    cout << cars[2][2] << " ";
    cout << cars[2][3] << " ";
    std::cout << endl;
}
