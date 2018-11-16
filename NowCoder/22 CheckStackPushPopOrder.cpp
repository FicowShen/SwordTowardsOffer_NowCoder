//
//  22 CheckStackPushPopOrder.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/14.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    
    if (pushV.size() != popV.size()) {
        return false;
    }
    
    return false;
}

void Solution::testCheckStackPushPopOrder() {
    
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    
    printf("%d\n", IsPopOrder(pushV, popV));
    
    popV = {4,3,5,1,2};
    printf("%d\n", IsPopOrder(pushV, popV));
}
