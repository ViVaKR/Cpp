#include "../include/Demo.hpp"
#include <iostream>
#include <math.h>

int main()
{
    // 기본 생성자 호출
    Demo<int, int> demoDefault;
    std::cout << "\n\033[1;31m[ 기본 생성자 호출 (`Demo<int, int> demoDefault;`)]\033[0m"
              << std::endl
              << "=> 버젓히 객체의 메모리 주소를 가지고 있음: " << &demoDefault
              << std::endl
              << "=> 기본 생성자는 생성된 오브젝트의 `메모리 주소` 및 `값`을 반환하는 등의 완전한 객체활동을 함"
              << std::endl
              << "=> 기본 인수 (1, 1)의 피타고라스 결과  값  = "
              << demoDefault.GetValue()
              << std::endl;

    // (파라미터 생성자) 범위를 벗어 나면 자동 삭제되는 오브젝트 생성
    std::cout
        << "\n\033[31m[ 파라미터 형식, 범위를 벗어 나면 자동 삭제되는 오브젝트 생성 (`Demo<float, double> demo(3.14, 4.3);`)]\033[0m"
        << std::endl;
    Demo<float, double> demo(3.14, 4.3); // parameterized constructor 호출
    std::cout << "=> 원본 (변경 전) => "
              << demo.GetValue()
              << std::endl;

    Demo<float, double> *demoCopy = &demo; // 복사 생성자 호출값
    demoCopy->SetValue(1.12345, 2.12345);  // 복사 본에서 값 변경

    std::cout << "=> 원본 (변경 후) => " << demo.GetValue() << std::endl;
    std::cout << "=> 복사  => " << demoCopy->GetValue() << std::endl;

    Demo<float, double> demo_copy = demo; // 복사 생성자 호출

    // 동적 할당된 오브젝트 생성
    std::cout << "\n\033[031m[ 동적 할당된 오브젝트 생성 (`Demo<int, int> *demoDynamic = new Demo<int, int>(3, 4);`)]\033[0m" << std::endl;
    Demo<int, int> *demoDynamic = new Demo<int, int>(3, 4);
    std::cout << "=> 원판 (변경 전) = " << demoDynamic->GetValue() << std::endl;

    // 복사 생성자를 이용한 객체 복사 생성
    std::cout << "\n\033[31m[ 복사 생성자를 이용한 객체 복사 생성 ]\033[0m" << std::endl;
    Demo<int, int> *demoDynamiCopy = new Demo<int, int>(*demoDynamic);
    demoDynamiCopy->SetValue(2, 2);
    std::cout << "=> 원본 (변경 후) = " << demoDynamic->GetValue() << std::endl
              << "=> 복사 = " << demoDynamiCopy->GetValue() << std::endl;

    delete demoDynamic;
    delete demoDynamiCopy;

    // (마무리)기본 생성자 호출 방법 중 또다른 방식
    Demo<int, int> demoDefault2 = Demo<int, int>();
    std::cout << "\n...테스트 마무리..." << std::endl;
    demoDefault2.Print();

    Demo<float, double> *demo3 = new Demo<float, double>(3.14, 4.3);
    std::cout << "주소: " << &demo3 << std::endl;

    std::cout << "정적 멤버 변수: " << demo3->staticValue << std::endl;

    delete demo3;
    return 0;
}
