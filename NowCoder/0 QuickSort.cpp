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


// MARK: - Sort with Partition function

int partition(int *values, int start, int end) {
    
    assert(start <= end);
    
    // 随机选取一个数，移至尾部，用于比较和分隔其他数
    int index = start + int(arc4random_uniform(end - start));
    swap(values[index], values[end]);
    
    
    int small = start - 1;
    
    for (index = start; index < end; index++) {
        // 把比end位置的数小的数，移到前面
        if (values[index] < values[end]) {
            small++;
            if (small != index) swap(values[small], values[index]);
        }
    }
    // 把end位置的数移回分隔位置
    small++;
    swap(values[small], values[end]);
    
    return small;
}


void quickSort2(int *values, int start, int end) {
    
    if (start >= end) {
        return;
    }
    
    int mid = partition(values, start, end);
    quickSort2(values, start, mid - 1);
    quickSort2(values, mid + 1, end);
}



// QuickSort
void Solution::testQuickSort() {
    
    int values0[10] = {6,1,2,7,9,3,4,5,10,8};
    quickSort(values0, 0, 9);
    printValues(values0, 10);

    int values1[10] = {6,1,2,7,9,3,4,5,10,8};
    quickSort2(values1, 0, 9);
    printValues(values1, 10);


    int values2[8] = {6,11,2,17,9,-55,10,88};
    quickSort(values2, 0, 7);
    printValues(values2, 8);

    int values3[8] = {6,11,2,17,9,-55,10,88};
    quickSort2(values3, 0, 7);
    printValues(values3, 8);
    
    
    double start = clock();
    const int SIZE = 5000;
    
    int values[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            values[j] = int(arc4random_uniform(SIZE));
        }
        quickSort(values, 0, SIZE);
    }
    printf("quickSort: %.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
    
    
    start = clock();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            values[j] = int(arc4random_uniform(SIZE));
        }
        quickSort2(values, 0, SIZE);
    }
    printf("quickSort2:%.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
    
}
