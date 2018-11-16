//
//  0 QuickSort.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/30.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"


void printValues(int *values, int length) {
    
    for (int i = 0; i < length; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

/**
 快速排序

 @param values 待排序的数组
 @param left 排序左边界的索引值
 @param right 排序右边界的索引值
 */
void quickSort(int values[], int left, int right) {
    
    if (left >= right) {
        return;
    }
    
    int base = values[left];
    int l = left, r = right;
    
    while (l != r) {
        while (l < r && values[r] >= base) r--;
        while (l < r && values[l] <= base) l++;
        
        if (l < r) {
            int t = values[l];
            values[l] = values[r];
            values[r] = t;
//            printValues(values, 10);
//            printf("l=%d, r=%d\n\n", l, r);
        }
    }
    
    if (values[l] != base) {
        values[left] = values[l];
        values[l] = base;
//        printValues(values, 10);
//        printf("base=%d, l=%d, r=%d\n\n", base, l, r);
    }
    
    quickSort(values, left, l - 1);
    quickSort(values, r + 1, right);
}


// QuickSort
void Solution::testQuickSort() {
    
    int values[10] = {6,1,2,7,9,3,4,5,10,8};
    quickSort(values, 0, 9);
    printValues(values, 10);
    
    int values1[8] = {6,11,2,17,9,-55,10,88};
    quickSort(values1, 0, 7);
    printValues(values1, 8);
}
