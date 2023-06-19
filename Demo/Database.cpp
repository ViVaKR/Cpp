#include <iostream>

using namespace std;

// 자료구조 2차 과제 - C++로 구현한 연결 리스트
typedef struct nodeRecord {
    int Data;
    struct nodeRecord *Next;
} node;

typedef node *Nptr;

class listClass {
  public:
    listClass();                            // 생성자
    ~listClass();                           // 소멸자
    void Insert(int Position, int Item);    // 해당 위치에 데이터 삽입
    void Delete(int Position);              // 해당 위치의 데이터 삭제
    void Retrieve(int Position, int &Item); // 해당 위치의 데이터 탐색
    bool IsEmpty();                         // 비어있는지 확인
    int Length();                           // 리스트 내 데이터 개수(리스트 길이)
  private:
    int Count; // 리스트 길이 추적
    Nptr Head; // 헤드 포인터로 리스트 전체를 대변함
};

void Database() {
    listClass L;                                               // 매개변수 없는 생성자 호출
    cout << "\nIsEmpty: " << boolalpha << L.IsEmpty() << endl; // boolalpha는 bool타입 출력 위해 사용
    cout << "\n삽입: \n";
    L.Insert(1, 10); // 위치 1에 데이터 10 삽입
    L.Insert(2, 70); // 위치 2에 데이터 70 삽입
    L.Insert(3, 40); // 위치 3에 데이터 40 삽입
    L.Insert(2, 30); // 위치 2에 데이터 30 삽입
    cout << "\n삭제: \n";
    L.Delete(2); // 위치 2의 데이터 삭제
    int Result ;  // 탐색한 데이터 탐색값 저장

    cout << "\n탐색: \n";
    L.Retrieve(2, Result);                         // 위치 2의 데이터를 탐색
    cout << "리스트 길이: " << L.Length() << endl; // 리스트의 길이(데이터 개수)
}

listClass::listClass() // 생성자 함수
{
    Count = 0;   // 리스트 길이를 0으로 초기화
    Head = NULL; // 헤드를 널로 초기화
    cout << "Count 초기화 -> " << Count << endl;
    cout << "Head 초기화 -> " << Head << endl;
}

listClass::~listClass() // 소멸자 함수
{
    while (!IsEmpty()) // 리스트가 완전히 빌 때까지
        Delete(1);     // 첫번째 것을 계속 지우기
}

bool listClass::IsEmpty() // 비어있는지 확인하는 함수
{
    if (Count == 0)
        return true; // Count가 0이면 true 반환
    else
        return false; // Count가 0이 아니면 false 반환
}

void listClass::Insert(int Position, int Item) // 삽입 함수
{
    if ((Position > (Count + 1)) || (Position < 1)) {
        cout << "Position out of Range\n\n"; // 이격된 삽입위치 불허
    } else {                                 // 클래스 내의 Data필드에 데이터 삽입
        node *p = new node;                  // 삽입될 노드의 공간 확보
        p->Data = Item;                      // 데이터 값 복사
        p->Next = NULL;                      // 삽입노드의 Next 초기화
        if (Position == 1) {                 // 첫 위치에 삽입할 경우
            p->Next = Head;                  // 삽입노드가 첫 노드를 가리킴
            Head = p;                        // 헤드가 삽입노드를 가리킴
        } else {                             // 삽입 위치가 첫 위치가 아닐 경우
            Nptr Temp = Head;                // 헤드 포인터를 Temp로 복사
            for (int i = 1; i < (Position - 1); i++) {
                Temp = Temp->Next; // Temp가 삽입 직전의 노드를 가리킴
            }
            p->Next = Temp->Next; // 삽입노드의 Next를 설정
            Temp->Next = p;       // 직전노드가 삽입노드를 가리킴
        }
        Count += 1; // 리스트 길이를 늘림
        cout << "위치 " << Position << "의 데이터: " << Item << " ";
        cout << "노드의 수 " << Count << endl;
    }
    cout << endl;
}
void listClass::Delete(int Position) // 삭제 함수
{
    if (IsEmpty())
        cout << "Deletion on Empty List\n\n"; // 빈 리스트에 삭제 요구는 오류
    else if (Position > Count || Position < 1)
        cout << "Position out of Range\n\n"; // 이격된 삭제위치 불허
    else                                     // 삭제할 데이터가 해당 위치에 있는 경우(클래스 내의 해당 위치의 데이터 삭제)
    {
        if (Position == 1) {   // 삭제될 노드가 첫 노드일 경우
            Nptr p = Head;     // 삭제될 노드를 가리키는 포인터를 백업
            Head = Head->Next; // 헤드가 둘째 노드를 가리킴
        } else {               // 삭제될 노드가 첫 노드가 아닌 경우
            Nptr Temp = Head;
            for (int i = 1; i < (Position - 1); i++) {
                Temp = Temp->Next; // Temp가 삭제될 노드인 직전 노드로 이동
            }
            Nptr p = Temp->Next;  // 삭제될 노드를 가리키는 포인터를 백업
            Temp->Next = p->Next; // 직전노드가 삭제될 노드 다음을 가리킴
            delete (p);
        }
        Count -= 1; // 리스트 길이 감소
        cout << "위치 " << Position << "에 있는 데이터 삭제\n";
        cout << "노드의 수 " << Count << endl;
    }
    cout << endl;
}

void listClass::Retrieve(int Position, int &Item) // 탐색 함수
{
    Nptr p = Head; // 탐색할 노드를 가리키는 포인터를 백업
    if (IsEmpty())
        cout << "Retrieve on Empty List\n\n"; // 빈 리스트에 탐색 요구는 오류
    else if (Position > Count || Position < 1)
        cout << "Position out of Range\n\n"; // 이격된 탐색위치 불허
    else {                                   // 데이터 탐색
        int Item = p->Data;
        cout << "탐색할 위치 " << Position << "의 데이터: " << Item << endl; // Item값을 main함수 내 Result로 반환
    }
    cout << endl;
}

int listClass::Length() // 리스트의 길이
{
    return Count;
}

// 왜 실행창에서 탐색할 위치 2의 데이터는 10으로 뜨고
// 리스트 길이 아래에는 왜 위치 1에 있는 데이터 삭제는 왜뜨나요

