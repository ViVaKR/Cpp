
#ifdef UTILS_HPP

template <class T>
T Utils<T>::Add()
{
    return data_a + data_b;
}

template <class T>
void Utils<T>::ToBinary(int num)
{
    if (num == 0) {
        return;                // base case
    } else {
        ToBinary(num / 2);     // recursive call 1 -> 2 -> 3 -> 4 (stact order)
        printf("%d", num % 2); // return 5 -> 6 -> 7 -> 8 ( Last(6) In First(9) Out )
    }
}

/*

--> recursive call with value --> `12`
( 콜 스택에 쌓이는 순서: 1 -> 4, 팝 하는 순서: 5 -> 8)
1 -->   { ToBinary(12) --> printf 0 [1100]  <-- 8 [ 최종 결과 ] ==> 1 1 0 0 { 6, 7, 8, 9 }
2 -->     { ToBinary(6) --> printf 0 [110]   <-- 7
3 -->       { ToBinary(3) --> printf 1 [11]   <-- 6
4 -->         { ToBinary(1) --> printf 1 [1]   <-- 5
- -->           { ToBinary(0) --> base case <-- if num == 0 is true, start return;

*/
#endif
