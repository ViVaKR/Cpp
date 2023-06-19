#include <iostream>
#include <stdlib.h>
#include <thread>
#include <time.h>

void Pro_Manage();
void Move(double a, double *cnt);

using namespace std;

/// @brief // 여기에서 1.5를 입력하면
/// 1.5 0 0 0 0 > 0.5 1 0 0 0 > 0.5 0 1 0 0 > 0.5 0 0 1 0 > 0.5 0 0 0 1 처럼 출력
/// @return
int MoveNumberToRight() {
    Pro_Manage();
    return 0;
}

void Pro_Manage() {

    double num;
    double cnt[5];
    std::fill(begin(cnt), end(cnt), 0);
    cout << "숫자 입력" << endl;
    cin >> num;
    cnt[0] = num;
    system("clear");
    std::cout << endl;
    Move(num, cnt);
}

void Move(double a, double *cnt) {
    int i, j, nm = a;
    for (i = 0; i < 5; i++) {
        cout << endl;
        for (j = 0; j < 5; j++)
            cout << cnt[j] << " ";
        cout << endl;
        cnt[i] = i == 0 ? cnt[i] - nm : (int)(cnt[i] - nm);
        cnt[i + 1] = nm;
        std::this_thread::sleep_for(1000ms);
        // system("clear");

        std::cout << endl;
    }
}
