#include <iostream>
#include <string.h>

using namespace std;

void Array2D() {

    // 2차원 배열 [행][열]
    string cars[][4] = {{"Grandeur", "Sonata", "Accent", "Viv-04"},
                        {"Mustang", "Escape", "F-150", "Viv-14"},
                        {"Corvette", "Equinox", "Silverade", "Viv-24"}};

    int rows = sizeof(cars) / sizeof(cars[0]);
    int columns = sizeof(cars[0]) / sizeof(cars[0][0]);
    cout << "행: " << rows << ", 열: " << columns << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << cars[i][j] << ", \t";
        }
        std::cout << endl;
    }
    std::cout << endl;

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
    std::cout << endl;

    string q[] = {"1. What year was C++ created?: ", "2. Who invented C++?: ",
                  "3. What is the predecessor of C++?: ", "4. is the Earth flat?: "};

    string options[][4] = {
        {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
        {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark zuckerburg"},
        {"A. C", "B. C+", "C. C--", "D. B++"},
        {"A. Yes", "B. No", "C. Sometimes", "D. What's Earth?"}};

    char ans[] = {'C', 'B', 'A', 'B'};

    int size = sizeof(q) / sizeof(q[0]);

    char guess;
    int score = 0;
    for (int i = 0; i < size; i++) {

        cout << string(40, '*');
        std::cout << endl;
        cout << q[i] << endl;
        cout << string(40, '*');
        std::cout << endl;

        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
            cout << options[i][j] << endl;
        }
        cout << ">>> ";
        std::cin >> guess;
        guess = toupper(guess);
        if (guess == ans[i]) // 채점
        {
            cout << "정답입니다! (CORRECT!)" << endl;
            score++;
        } else {
            cout << "오답입니다! (WRONG!)" << endl;
            cout << "답 (Answer): " << ans[i] << endl;
        }
    }
    cout << string(40, '*');
    std::cout << endl;
    cout << "당신의 점수는 : " << score << endl;
    cout << "# of QUESTIONS: " << size << endl;
    cout << "SCORE: " << ((double)score / (double)size) * 100 << " %" << endl;
    cout << string(40, '*');
    std::cout << endl;
}
