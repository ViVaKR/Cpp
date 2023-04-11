#include <iostream>

using namespace std;

int main()
{
    int month;
    cout << "Enter the month (1-12) ";
    cin >> month;

    switch (month)
    {
    case 1:
        cout << "1월 (January, Jan)\n";
        break;
    case 2:
        cout << "2월 (February, Feb)\n";
        break;
    case 3:
        cout << "3월 (March, Mar)\n";
        break;
    case 4:
        cout << "4월 (April, Apr)\n";
        break;
    case 5:
        cout << "5월 (May, May)\n";
        break;
    case 6:
        cout << "6월 (June, Jun)\n";
        break;
    case 7:
        cout << "7월 (July, Jul)\n";
        break;
    case 8:
        cout << "8월 (August, Aug)\n";
        break;
    case 9:
        cout << "9월 (September, Sep\n";
        break;
    case 10:
        cout << "10월 (October, Oct)\n";
        break;
    case 11:
        cout << "11월 (November, Nov)\n";
        break;
    case 12:
        cout << "12월 (December, Dec)\n";
        break;
    default:
        cout << "Please enter in only number (1-12)";
        break;
    };

    return 0;
}
