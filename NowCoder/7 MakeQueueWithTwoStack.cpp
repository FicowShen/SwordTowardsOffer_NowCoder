//
//  5 MakeQueueWithTwoStack.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/25.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"
#include <stack>

stack<int> stack1;
stack<int> stack2;

/**
 两个栈模拟一个队列

 @param node 即将压入栈顶的值
 */
void push(int node) {
    
    stack1.push(node);
}


/**
 两个栈模拟一个队列

 @return 弹出栈顶的值
 */
int pop() {
    
    if (stack2.empty()) {
        while (!stack1.empty()) {
            int val = stack1.top();
            stack2.push(val);
            stack1.pop();
        }
    }
    if (stack2.empty()) {
        throw;
    }
    int res = stack2.top();
    stack2.pop();
    return res;
}

void Solution::testMakeQueueWithTwoStack() {
    
    push(7);
    push(3);
    
    printf("%d\n", pop());
    
    push(2);
    
    printf("%d\n", pop());
    printf("%d\n", pop());
}
