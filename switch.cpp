#include <iostream>

using namespace std;

int main() {
    int month;
    cout << "Enter the month (1-12) ";
    cin >> month;

    switch (month) {
        case 1:
            cout << "1월 (January)\n";
            break;
        case 2:
            cout << "2월 (February)\n";
            break;
        case 3:
            cout << "3월 (March)\n";
            break;
        case 4:
            cout << "4월\n";
            break;
        case 5:
            cout << "5월\n";
            break;
        case 6:
            cout << "6월\n";
            break;
        case 7:
            cout << "1월\n";
            break;
        case 8:
            cout << "1월\n";
            break;
        case 9:
            cout << "1월\n";
            break;
        case 10:
            cout << "1월\n";
            break;
        case 11:
            cout << "1월\n";
            break;
        case 12:
            cout << "1월\n";
            break;
        default:
            break;
    };

    return 0;
}