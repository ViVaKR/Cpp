//
//  TernaryOperator.cpp
//  HelloWorld
//
//  Created by 김범준 on 2023/04/11.
//

#include "HelloWorldHeader.h"

void TernaryOperator(){
    
    // ternary operator ?:= replacement to an if/else statement
    // dondition ? expression1 : expression2;
    
    // type 1
    int grade = 75;
    if (grade >=60) {
        cout << "You pass!";
    }else{
        cout << "You fail!";
    }
    cout << endl;
    
    // type 2
    grade >=60 ? cout << "You pass!" : cout << "You fail!";
    cout << endl;
    
    // type 3
    cout << ((grade >=60) ? "You pass!" : "You fail!");
    cout << endl;
}
