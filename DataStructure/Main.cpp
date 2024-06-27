#include <iostream>
#include <list>
using namespace std;

int Search(int mat[4][4], int n, int x)
{
    if (n == 0) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == x) {
                std::cout << "Element found at (" << i << ", " << j << ")\n";
                return 1;
            }
        }
    }
    return 0;
}

void List()
{
    // list : 양방향 연결 리스트(Doubly Linked List)
    // - push_front, pop_front, push_back, pop_back, insert, erase, clear, size, empty, front, back, begin, end, rbegin, rend
    // - remove, remove_if, unique, sort, merge, reverse, splice, swap, resize, assign, emplace, emplace_front, emplace_back, push_front, push_back, pop_front, pop_back, insert, erase, clear, size, empty, front, back, begin, end, rbegin, rend
    list<int> list1;
}

int main()
{
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    Search(mat, 4, 29);
    return 0;
}

/*
--> STL (Standard Template Library)
1. 알고리즘 (Algorithm)
    - 컨테이너에 저장된 데이터를 처리하는 함수 객체를 제공한다.
    - sort, binary_search, find, count, copy, transform, accumulate, for_each, generate, fill, reverse, swap, min, max, equal, mismatch, unique, remove, replace, partition, stable_partition, merge, set_union, set_intersection, set_difference, set_symmetric_difference, includes, lexicographical_compare, next_permutation, prev_permutation, random_shuffle, nth_element, partial_sort, partial_sort_copy, is_sorted, is_heap, is_partitioned, is_permutation, is_sorted_until, is_heap_until, is_partitioned_until, is_permutation_until, is_sorted_copy, is_heap_copy, is_partitioned_copy, is_permutation_copy, is_sorted_until_copy, is_heap_until_copy, is_partitioned_until_copy, is_permutation_until_copy

2. 컨테이너 (Container)
    - 데이터를 저장하는 객체를 제공한다.
    - vector, deque,
    - list : 양방향 연결 리스트 (Doubly Linked List) - push_front, pop_front, push_back, pop_back, insert, erase, clear, size, empty, front, back, begin, end, rbegin, rend
    - forward_list, array, stack, queue, priority_queue, set, multiset, map, multimap, unordered_set, unordered_multiset, unordered_map, unordered_multimap, bitset

3. 함수 객체 (Function Object)
    - 함수처럼 동작하는 객체를 제공한다.
    - plus, minus, multiplies, divides, modulus, negate, equal_to, not_equal_to, greater, less, greater_equal, less_equal, logical_and, logical_or, logical_not, bit_and, bit_or, bit_xor, bit_not, not1, not2, bind1st, bind2nd, mem_fun, mem_fun_ref, mem_fun1, mem_fun1_ref, ptr_fun, unary_function, binary_function, pointer_to_unary_function, pointer_to_binary_function, unary_negate, binary_negate, not1, not2, bind1st, bind2nd, mem_fun, mem_fun_ref, mem_fun1, mem_fun1_ref, ptr_fun, unary_function, binary_function, pointer_to_unary_function, pointer_to_binary_function, unary_negate, binary_negate

4. 반복자 (Iterator)
    - 컨테이너에 저장된 데이터를 순회하는 객체를 제공한다.
    - input_iterator, output_iterator, forward_iterator, bidirectional_iterator, random_access_iterator, iterator, reverse_iterator, move_iterator, back_insert_iterator, front_insert_iterator, insert_iterator, istream_iterator, ostream_iterator, istreambuf_iterator, ostreambuf_iterator

*/

/*
--> Data Structure (데이터 구조)
- 데이터 구조는 데이터를 효율적으로 저장하고 관리하는 방법을 의미한다.
1. 효율적인 데이터 관리
2. 데이터 구성
3. 데이터 처리
4. 데이터 저장
5. 데이터 검색
6. 데이터 정렬
7. 데이터 삭제
8. 데이터 삽입
9. 데이터 갱신
10. 데이터 병합
11. 데이터 분할
12. 데이터 복사
13. 데이터 이동
14. 데이터 교환
15. 데이터 분석
16. 데이터 추출
17. 데이터 연결
18. 데이터 분리

- 데이터 구조의 분류
1. 선형 구조 : 데이터를 일렬로 나열한 구조
    - 배열 (정적 배열, 동적 배열, 연결 배열, 연결 동적 배열, 연결 리스트 배열, 연결 리스트 동적 배열, 연결 리스트 연결 배열, 연결 리스트 연결 동적 배열)
    - 연결 리스트 (단일 연결 리스트, 이중 연결 리스트, 원형 연결 리스트, 이중 원형 연결 리스트)
    - 스택 (후입선출)
    - 큐 (대기열)
    - 덱 (양방향 큐)
    - 리스트 (연결 리스트)
2. 비선형 구조 : 데이터를 여러 개의 하위 구조로 나눈 구조
    - 트리
    - 그래프
    - 힙
    - 해시 테이블
    - 맵
    - 집합
 */
