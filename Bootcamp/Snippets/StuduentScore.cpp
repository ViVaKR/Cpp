#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>

using namespace std;
double InputNumber(string key);

void StudentScore() {
    map<string, double> score;

    score["국어"] = 0;
    score["영어"] = 0;
    score["수학"] = 0;

    cout << score.size() << endl;
    cout << "***** 성적을 입력을 시작하겠습니다. *****" << endl;

    double value;
    for (auto const &[key, val] : score) {
        score[key] = InputNumber(key);
    }

    int total_sum = std::accumulate(score.begin(), score.end(), 0, [](auto prev_sum, auto &entry) {
        return prev_sum + entry.second;
    });

    for (auto const &[key, val] : score) {
        std::cout << key << ':' << val << std::endl;
    }

    char ch;
    double avg = (double)(total_sum) / (double)score.size();
    switch ((int)(avg * 10.0)) {
        case 900 ... 1000: ch = 'A'; break;
        case 800 ... 899: ch = 'B'; break;
        case 700 ... 799: ch = 'C'; break;
        case 500 ... 699: ch = 'D'; break;
        default: ch = 'F'; break;
    }
    std::cout << endl;
    cout << std::string(60, '*') << endl;
    cout << "귀하의 평균 점수는: " << std::setprecision(2) << std::fixed << avg << " 입니다."
         << endl;
    cout << "귀하의 학점은 " << ch << " 입니다." << endl;
    cout << std::string(60, '*') << endl;
}

// Is Double Number Check
double InputNumber(string key) {

    string str;
    // regex regex_pattern("-?[0-9]+.?[0-9]+");
    regex regex_pattern("[0-9]+");
    do {
        cout << key << " 점수를 입력하세요 (): ";
        cin >> str;
    } while (!regex_match(str, regex_pattern) || stod(str) > 100 || stod(str) < 0);

    return stod(str);
}
