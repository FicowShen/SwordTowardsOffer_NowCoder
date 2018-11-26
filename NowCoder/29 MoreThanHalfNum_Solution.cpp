//
//  29 MoreThanHalfNum_Solution.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/26.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

int MoreThanHalfNum_Solution(vector<int> numbers) {
    
    int result = INT_MIN;
    long count = 0;
    
    long size = numbers.size();
    for (long i = 0; i < size ; i++) {
        if (count == 0) {
            result = numbers[i];
            count = 1;
        }else if (numbers[i] == result) {
            count++;
        }else{
            count--;
        }
    }
    
    if (count <= 0) return 0;
    
    count = 0;
    for(auto i: numbers) {
        if (i == result) {
            count++;
        }
    }
    
    return count * 2 < size ? 0 : result;
}

void Solution::testMoreThanHalfNum() {
    
    printf("%d\n", MoreThanHalfNum_Solution({1,2,3,2,2,2,5,4,2}));
    printf("%d\n", MoreThanHalfNum_Solution({1,2,3}));
    printf("%d\n", MoreThanHalfNum_Solution({}));
}
