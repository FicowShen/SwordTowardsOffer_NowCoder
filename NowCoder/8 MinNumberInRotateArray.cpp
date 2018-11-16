//
//  6 MinNumberInRotateArray.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/26.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 已排序数组在被旋转后，找到其中最小元素。
 如：34512，是由12345旋转而来，最小元素是1

 @param rotateArray 被旋转了的数组
 @return 最小元素的值
 */
int minNumberInRotateArray(vector<int> rotateArray) {
    
    if (rotateArray.empty()) {
        return 0;
    }
    
    long size = rotateArray.size();
    if (size == 1) {
        return rotateArray[0];
    }
    
    long l = 0;
    long r = size - 1;
    long mid = (l + r) / 2;
    
    // 1,2,3
    if (rotateArray[l] < rotateArray[r]) {
        return rotateArray[l];
    }
    // 1,1,1,0,1ß
    if (rotateArray[l] == rotateArray[r]
              && rotateArray[mid] == rotateArray[l]) {
        
        int min = rotateArray[l];
        for (int i = 0; i < size; i++) {
            if (rotateArray[i] < min) {
                min = rotateArray[i];
            }
        }
        return min;
    }
    // 3,4,5,1,2
    while (r - l > 1) {
        if (rotateArray[mid] >= rotateArray[l]) {
            l = mid;
            mid = (l + r) / 2;
            continue;
        }
        if (rotateArray[mid] <= rotateArray[r]) {
            r = mid;
            mid = (l + r) / 2;
            continue;
        }
    }
    return rotateArray[r];
}

void Solution::testMinNumberInRotateArray() {
    
    vector<int> v;
    
    v = {};
    printf("%d\n", minNumberInRotateArray(v));
    
    v = {3};
    printf("%d\n", minNumberInRotateArray(v));
    
    v = {3,4,5,1,2};
    printf("%d\n", minNumberInRotateArray(v));
    
    v = {1,1,1,0,1};
    printf("%d\n", minNumberInRotateArray(v));
    
    v = {3,4,5};
    printf("%d\n", minNumberInRotateArray(v));
}
