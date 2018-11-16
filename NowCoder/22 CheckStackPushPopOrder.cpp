//
//  22 CheckStackPushPopOrder.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/14.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    
    if (pushV.empty() || popV.empty() || pushV.size() != popV.size()) {
        return false;
    }
    
    stack<int> s;
    
    int pushIndex = 0, popIndex = 0, endIndex = pushV.size();
    
    while (popIndex < endIndex) {
        
        while (s.empty() || s.top() != popV[popIndex]) { // 栈空、栈顶无法弹出
            if (pushIndex < endIndex) { // 可以继续入栈
                s.push(pushV[pushIndex++]);
            }else{ // 无法继续入栈
                break;
            }
        }
        
        if (!s.empty() && s.top() != popV[popIndex]) { // 栈顶无法弹出
            return false;
        }
        
        // 弹出栈顶
        popIndex++;
        s.pop();
        
    }
    
//    while (popIndex < endIndex) {
//
//            if (!s.empty() && s.top() == popV[popIndex]) { // 弹出栈顶
//                popIndex++;
//                s.pop();
//            }else if (pushIndex < endIndex) { // 可以继续入栈
//                s.push(pushV[pushIndex++]);
//            }else{ // 无法弹出栈顶、无法继续入栈，必然不是有效的弹出序列
//                return false;
//            }
//    }
    
    return true;
}

void Solution::testCheckStackPushPopOrder() {
    
    vector<int> pushV;
    vector<int> popV;
    
    assert(!IsPopOrder(pushV, popV));
    
    pushV = {1,2,3,4,5};
    assert(!IsPopOrder(pushV, popV));
    
    popV = {4,5,3,2,1};
    assert(IsPopOrder(pushV, popV));
    
    popV = {4,3,5,1,2};
    assert(!IsPopOrder(pushV, popV));
}
