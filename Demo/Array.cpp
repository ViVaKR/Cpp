#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>

using namespace std;

double GetTotal(double p[], int size);
int SerarchArray(int array[], int size, int element);
int SerarchArray(string array[], int size, string element);
void SortNumberArray(int array[], int size, bool asc);

/// @brief Array Examples Entry Point (ref Bro Code)
void Array() {
    // array = A data structure ahat can hold multiple values
    //          values are accessed by an index number
    //          "kind of like a variable that holds multiple values"
    // 동일한 유형의 데이터

    // 유형 (1)
    string cars[] = {"Accent", "Grandeur", "Sonata", "Xcent", "Corvette", "Mustang", "Camry"};
    // sizeof(car) : 32 bytes * 7 items = 224 bytes
    cars[0] = "Tucson"; // 배열 요소 수정
    // 배열 출력 : 인덱스 번호 `0` 부터 시작
    cout << cars[0] << endl;
    cout << cars[1] << endl;

    // 유형 (2)
    // 선언만 하고 나중에 할당할 수 있음
    // 배열의 크기는 필수 사항
    int numbers[10];
    numbers[0] = 100;
    numbers[1] = 200;
    numbers[2] = 300;
    cout << numbers[0] << endl;
    cout << numbers[2] << endl;

    // 유형 (3)
    // sizeof(prices) : 8 bytes * 3 items = 24 bytes
    double prices[] = {49.99, 15.05, 75, 5.00, 7.50, 9.99};
    cout << prices[0] << endl;

    // sizeof() = determins the size in bytes of a:
    //            variable, data type, class, objects, etc.

    char grades[] = {'A', 'B', 'C', 'D', 'F'}; // 1 byte * 5 items = 5 bytes
    char grade = 'A';                          // 1 byte
    bool tf = true;                            // 1byte
    int num = 12345;                           // 4 bytes
    string name = "Hello Viv World";           // 32 bytes
    double gpa = 2.5;                          // 8 bytes

    cout << endl
         << "***** Sizes *****\n"
         << "array: " << sizeof(cars) << " bytes, \nchar: " << sizeof(grade)
         << " bytes,\nbool: " << sizeof(tf) << " bytes, \nint: " << sizeof(num)
         << " bytes, \nstring: " << sizeof(name) << " bytes, \ndouble: " << sizeof(gpa) << " bytes"
         << endl;

    cout << "Get Array `cars` Length (sizeof(cars) / sizeof(cars[0])): "
         << sizeof(cars) / sizeof(cars[0]) << endl;

    // 배열 요소 순회하기
    // for loop
    string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};
    int length = sizeof(students) / sizeof(string);

    cout << "\n\n***** All of sutdents list *****\n\n";
    for (int i = 0; i < length; i++) {
        cout << students[i] << endl;
    }
    std::cout << endl;
    for (int i = 0; i < sizeof(grades) / sizeof(char); i++) {
        cout << grades[i] << endl;
    }

    // for each loop
    // Eases the traversal over an iterable data set
    // 반복 가능한 데이터 세트에 대한 순회를 용이하게 하는 반복문
    cout << "for each loop" << endl;
    for (char c : grades) {
        cout << c << endl;
    }
    std::cout << endl;

    cout << "for each loop (auto)" << endl;
    for (auto &&i : students) {
        cout << i << endl;
    }

    int scores[] = {1, 3, 44, 55, 993, 100, 0, 23432};

    for (int i : scores) {
        cout << i << endl;
    }

    // 합계 구하기
    cout << "합계구하기\n";
    double p[] = {49.99, 15.05, 75, 5.00, 7.50, 9.99};
    int size = sizeof(p) / sizeof(double);
    double total = GetTotal(p, size);
    cout << "Total $" << total << endl;

    // 배열 요소의 인덱스 번호 구하기 (int)
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size = sizeof(nums) / sizeof(int);
    int index;
    int myNum;
    cout << "Enter nums element to search for!\n(1, 2, 3, 4, 5, 6, 7, 8, 9, 10): ";
    std::cin >> myNum;
    index = SerarchArray(nums, size, myNum);
    if (index != -1)
        cout << "choice number " << myNum << " index is " << index << endl;
    cin.clear();
    cin.ignore(1000, '\n');

    // 배열 요소의 인덱스 번호 구하기 (string)
    string foods[] = {"pizza", "hamburger", "hotdog", "rice"};
    size = sizeof(foods) / sizeof(string);
    string myFood;
    std::cout << endl;
    std::cout << endl;

    cout << "Enter Food element to search for\n(pizza, hamburger, hotdog, rice): ";
    std::getline(std::cin, myFood);
    index = SerarchArray(foods, size, myFood);
    if (index != -1)
        cout << myFood << " Index is -> (" << index << ")\nPress Enter" << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    // 배열 일시 초기화
    int n[5];
    fill(n, n + 5, 123);
    for (int i = 0; i < sizeof(n) / sizeof(int); i++)
        cout << n[i] << endl;

    // 배열정렬 (순방향)
    int nms[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    size = sizeof(nms) / sizeof(nms[0]);

    SortNumberArray(nms, size, true); // true : asc, false : desc
    for (int i : nms) {
        cout << i << " ";
    }

    // 배열정렬 (역방향)
    std::cout << endl;
    SortNumberArray(nms, size, false); // true : asc, false : desc
    for (int i : nms) {
        cout << i << " ";
    }
    std::cout << endl;

    // fill() : Fills a range of elements with a specified value fill(gegin, end, value)
    const int SIZE = 100;
    string fds[SIZE];
    fill(fds, fds + (SIZE / 3), "pizza");
    fill(fds + (SIZE / 3), fds + (SIZE / 3) * 2, "hamburger");
    fill(fds + (SIZE / 3) * 2, fds + SIZE, "hotdog");
    for (string f : fds) {
        cout << f << endl;
    }

    std::cin.clear();
    // input array items : pizza, hambugger, hotdog, gimchi, ramyen
    string fs[5];
    size = sizeof(fs) / sizeof(fs[0]);

    string temp; // for `q` - quit check
    for (int i = 0; i < size; i++) {
        cout << "Enter a food you like or 'q' to quit #" << i + 1 << ": ";
        std::getline(std::cin, temp);
        if (temp == "q")
            break;
        fs[i] = temp;
    }

    cout << "You like the following food:" << endl;
    for (int i = 0; !fs[i].empty(); i++) { // 빈 배열까지만
        cout << i + 1 << ". " << fs[i] << endl;
    }
}

/// @brief 배열 합계구하기
/// @param p
/// @param size
/// @return
double GetTotal(double p[], int size) {

    double total = 0;
    for (int i = 0; i < size; i++) {
        total += p[i];
    }
    return total;
}

/// @brief 배열요소의 인덱스 구하기 (int)
/// @param array
/// @param size
/// @param element
/// @return
int SerarchArray(int array[], int size, int element) {

    int index;
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

/// @brief 배열요소의 인덱스 구하기 (string)
/// @param array
/// @param size
/// @param element
/// @return
int SerarchArray(string array[], int size, string element) {

    int index;
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

/// @brief Ascceding Order
/// @param array
/// @param size
void SortNumberArray(int array[], int size, bool asc) {

    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (asc) { // ascending
                if (array[j] > array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            } else { // descending
                if (array[j] < array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}
// Ref. Bro Code.
