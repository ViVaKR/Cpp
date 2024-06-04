#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <map>
#include <stack>

using namespace std;

// 최대 노드 개수 정의
const int MAX_NODES = 100;

// 이진 탐색 트리 (배열 기반)
class BinarySearchTree
{
private:
    int data[MAX_NODES];
    int left[MAX_NODES];
    int right[MAX_NODES];
    int numNodes;
    int root;

    // 삽입 함수
    void insert(int value)
    {
        if (numNodes >= MAX_NODES)
        {
            cout << "Error: 트리가 가득 찼습니다." << endl;
            return;
        }

        int newNodeIndex = numNodes; // 새로운 노드의 인덱스
        int parentIndex = -1;        // 삽입할 위치의 부모 노드 인덱스
        int current = root;          // 현재 노드의 인덱스

        // 삽입할 위치 찾기
        while (current != -1)
        {
            parentIndex = current;
            if (value < data[current])
            {
                current = left[current];
            }
            else
            {
                current = right[current];
            }
        }

        // 트리가 비어있는 경우
        if (parentIndex == -1)
        {
            root = newNodeIndex;
        }
        else if (value < data[parentIndex])
        {
            left[parentIndex] = newNodeIndex;
        }
        else
        {
            right[parentIndex] = newNodeIndex;
        }

        // 노드 추가
        data[newNodeIndex] = value;
        left[newNodeIndex] = -1;
        right[newNodeIndex] = -1;
        numNodes++;
    }

    // 검색 함수
    bool search(int value) const
    {
        int i = root;
        while (i != -1 && data[i] != value)
        {
            if (value < data[i])
            {
                i = left[i];
            }
            else
            {
                i = right[i];
            }
        }
        return (i != -1 && data[i] == value);
    }

    // 삭제 함수
    void deleteNode(int value)
    {
        int i = findNode(value);
        if (i == -1)
        {
            cout << "Error: 삭제하려는 값을 찾을 수 없습니다." << endl;
            return;
        }

        if (left[i] == -1 && right[i] == -1)
        { // Leaf node
            replaceParentReference(i, -1);
        }
        else if (left[i] != -1 && right[i] == -1)
        { // Only left child
            replaceParentReference(i, left[i]);
        }
        else if (left[i] == -1 && right[i] != -1)
        { // Only right child
            replaceParentReference(i, right[i]);
        }
        else
        { // Two children
            int successor = findSuccessor(i);
            data[i] = data[successor];
            deleteNode(data[successor]);
        }
    }

    // 부모 노드의 자식 포인터를 업데이트하는 함수
    void replaceParentReference(int i, int newChild)
    {
        int parent = getParent(i);
        if (parent == -1)
        {
            root = newChild;
        }
        else if (left[parent] == i)
        {
            left[parent] = newChild;
        }
        else
        {
            right[parent] = newChild;
        }
    }

    // 특정 노드의 후속자를 찾는 함수
    int findSuccessor(int i)
    {
        int successor = right[i];
        while (left[successor] != -1)
        {
            successor = left[successor];
        }
        return successor;
    }

    // 특정 노드의 부모 노드를 찾는 함수
    int getParent(int i)
    {
        if (i == root)
            return -1;
        int parent = -1;
        int current = root;
        while (current != -1 && current != i)
        {
            parent = current;
            if (data[i] < data[current])
            {
                current = left[current];
            }
            else
            {
                current = right[current];
            }
        }
        return parent;
    }

    // 특정 값의 노드를 찾는 함수
    int findNode(int value) const
    {
        int i = root;
        while (i != -1 && data[i] != value)
        {
            if (value < data[i])
            {
                i = left[i];
            }
            else
            {
                i = right[i];
            }
        }
        return i;
    }

public:
    // 생성자
    BinarySearchTree()
    {
        numNodes = 0;
        root = -1;
    }

    // 값 삽입
    void insertValue(int value)
    {
        insert(value);
    }
    // 위 코드에서 실행시
    int findNode(int value)
    {
        int i = root;
        while (i != -1 && data[i] != value)
        {
            if (value < data[i])
            {
                i = left[i];
            }
            else
            {
                i = right[i];
            }
        }
        return i;
    }

    // 중위 순회 출력
    void inorder() const
    {
        if (root == -1)
        {
            cout << "트리가 비어 있습니다." << endl;
            return;
        }
        stack<int> s;
        int current = root;

        while (current != -1 || !s.empty())
        {
            while (current != -1)
            {
                s.push(current);
                current = left[current];
            }

            current = s.top();
            s.pop();
            cout << data[current] << " ";
            current = right[current];
        }
    }

    // 전위 순회 출력
    void preorder(int i = -1) const
    {
        if (i == -1)
        {
            i = root;
        }
        if (i != -1)
        {
            cout << data[i] << " ";
            preorder(left[i]);
            preorder(right[i]);
        }
    }

    // 후위 순회 출력
    void postorder(int i = -1) const
    {
        if (i == -1)
        {
            i = root;
        }
        if (i != -1)
        {
            postorder(left[i]);
            postorder(right[i]);
            cout << data[i] << " ";
        }
    }

    // 값 삭제
    void deleteValue(int value)
    {
        deleteNode(value);
    }

    // 값 검색
    bool searchValue(int value) const
    {
        return search(value);
    }

    // (1) Runner
    static void EntryPoint()
    {
        srand(time(0));

        BinarySearchTree tree;

        char input[256];
        int value; // value 변수 선언
        cout << "삽입할 숫자들을 입력하세요: ";
        fgets(input, sizeof(input), stdin); // scanf_s 대신 fgets 사용
        istringstream iss(input);
        while (iss >> value)
        {
            tree.insertValue(value);
        }

        // 숫자들을 삭제
        cout << "삭제할 숫자들을 입력하세요: "; // 삭제할 숫자를 입력받는 부분
        fgets(input, sizeof(input), stdin);     // scanf_s 대신 fgets 사용
        istringstream issDelete(input);
        while (issDelete >> value)
        {
            tree.deleteValue(value);
        }

        // 순회 결과 출력
        cout << "전위 순회 결과: ";
        tree.preorder();
        cout << "\n중위 순회 결과: ";
        tree.inorder();
        cout << "\n후위 순회 결과: ";
        tree.postorder();

        // 값을 검색하고 결과 출력
        cout << "\n찾을 숫자를 입력하세요: ";
        string inputStr;
        getline(cin, inputStr); // 문자열로 입력 받기

        // 입력 받은 문자열이 숫자로만 구성되어 있는지 확인
        bool isValidInput = true;
        for (char c : inputStr)
        {
            if (!isdigit(c))
            {
                isValidInput = false;
                break;
            }
        }

        // 입력이 올바르지 않은 경우 오류 메시지 출력 후 프로그램 종료
        if (!isValidInput)
        {
            cout << "Error: 올바른 숫자를 입력하세요." << endl;
            return;
        }

        value = stoi(inputStr); // 문자열을 정수로 변환
        cout << "숫자 " << value << " 검색 결과: ";
        if (tree.searchValue(value))
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }
};
