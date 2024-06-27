#include <iostream>

using namespace std;

void Strings()
{
    // 문자열
    // https://cplusplus.com/reference/string/string/?kw=string
    cout << endl
         << std::string(80, '*')
         << endl
         << endl;
         
    string name;
    cout << "이름을 입력하세요 : ";
    cin.ignore();
    getline(cin, name);
     
    if (name.empty()) // 변수가 비어 있는 지 체크
    {
        std::cout << "You didn't enter your name\n";
        return;
    }

    if (name.length() > 12) // 문자열의 길이 구하기
    {
        std::cout << "Your name can't be over 12 characters\n";
        return;
    }

    std::cout << "공백 인덱스 번호 : " << name.find(' ') << endl; // 처음 공백 하나의 인덱스 만 반환

    name.append("@gmail.com"); // 끝에 추가
    name.insert(0, "Hello");   // 삽입
    std::cout << "Welcome!\n"
              << name << endl;

    std::cout << name.at(4) << endl
              << "string length = " << name.length() << endl;

    std::cout << "Erase Before : " << name << endl;
    name.erase(1, 3);
    std::cout << "Erase After : " << name << endl;

    name.clear(); // 문자열 비우기
}
