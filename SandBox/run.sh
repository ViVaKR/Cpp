#! /usr/bin/env zsh


$(which clang++) \
-fcolor-diagnostics \
-fansi-escape-codes \
-std=c++23 \
-g main.cpp \
-o ./bin/SandBoxEx \
&& \
./bin/SandBoxEx $1 $2 $3 $4 $5 $6 $7 $8 $9

# cmake --build ./build && ./bin/SandBox

case "$?" in
0)
    clear
    ;;
1[0-9])
    echo "Return 10-19"
    ;;
2[0-9])
    echo "Return 20-29"
    ;;
3[0-9])
    echo "Return 30-39"
    ;;
4[0-9])
    echo "Return 40-49"
    ;;
5[0-9])
    echo "Return 50-59"
    ;;
6[0-9])
    echo "Return 60-69"
    ;;
7[0-9])
    echo "Return 70-79"
    ;;
8[0-9])
    echo "Return 80-89"
    ;;
9[0-9])
    echo "Return 90-99"
    ;;
*)
    echo "Success"
    ;;
esac
