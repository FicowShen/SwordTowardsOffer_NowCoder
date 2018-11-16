//
//  21 StackWithMinFunction.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/14.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

stack<int> valueStack;
stack<int> minStack;

void push1(int value) {

    valueStack.push(value);
    if (minStack.empty()) {
        minStack.push(value);
    }else{
        int currentMin = minStack.top();
        if (value < currentMin) {
            minStack.push(value);
        }else{
            minStack.push(currentMin);
        }
    }
}

void pop1() {

    valueStack.pop();
    minStack.pop();
}

int top1() {

    return valueStack.top();
}

int min1() {
    return minStack.top();
}

void testValue(int value) {

    push1(value);
    printf("top=%d, min=%d\n", top1(), min1());
    
}

void Solution::testStackWithMinFunction() {
    
    testValue(4);
    testValue(2);
    testValue(1);
    testValue(3);
    testValue(1);
    pop1();
    testValue(5);
    pop1();
    pop1();
    pop1();
    testValue(3);
    
}
