//
//  31 FindGreatestSumOfSubArray.cpp
//  NowCoder
//
//  Created by Ficow on 2018/12/1.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

int FindGreatestSumOfSubArray(vector<int> array) {
    
    if (array.empty()) {
        return 0;
    }
    
    long size = array.size();
    int maximum = array[0];
    int sum = maximum;
    
    for (long i = 1; i < size; i++) {
        
        int s = array[i] + maximum;
        printf("array[i]: %d, maximum: %d, sum: %d\n", array[i], maximum, s);
        if (s < array[i]) {
            printf("maximum = %d\n", maximum);
            sum = array[i];
            maximum = array[i];
            continue;
        }
        
        if (s > maximum) {
            maximum = s;
        }
        
    }
    
    return maximum;
}

void Solution::testFindGreatestSumOfSubArray() {
    
    vector<int> array = {1,-2,3,10,-4,7,2,-5};
    printf("%d\n", FindGreatestSumOfSubArray(array));
}
