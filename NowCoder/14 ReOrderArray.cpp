//
//  13 ReOrderArray.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/30.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 快速排序
 */
void sortArray(vector<int> &array, long left, long right) {
    
    if (left >= right) {
        return;
    }
    
    int flag = array[left];
    long l = left, r = right;
    
    while (l != r) {
        while (l < r && array[r] >= flag) r--;
        while (l < r && array[l] <= flag) l++;
        if (l < r) {
            int t = array[l];
            array[l] = array[r];
            array[r] = t;
        }
    }
    
    if (array[l] != flag) {
        array[left] = array[l] ;
        array[l] = flag;
    }
    
    sortArray(array, left, l - 1);
    sortArray(array, r + 1, right);
}


bool isEven(int n) {
    return n % 2 == 0;
}


/**
 将数组中的奇数置于偶数前面，并保证原有的相对顺序

 @param array 数组
 @param func 谓词函数
 */
void reOrderArray(vector<int> &array, bool (*func)(int)) {
    
    if (array.empty()) {
        return;
    }
    
    long left = 0, right = array.size() - 1;
    
    while (left != right) {
        while (left < right && !func(array[left])) left++;
        while (left < right && func(array[right])) right--;
        if (left < right) {
            int t = array[left];
            array[left] = array[right];
            array[right] = t;
        }
    }
    
    sortArray(array, 0, left - 1);
    sortArray(array, right, array.size() - 1);
}


/**
 另一种解法，保证原有的相对顺序，复杂度较高
 */
void reOrderArray2(vector<int> &array) {

    int i = 0,j;
    while(i<array.size()){
        while(i<array.size() && !isEven(array[i])) i++;
        j = i+1;
        while(j<array.size() && isEven(array[j])) j++;
        if(j<array.size()){
            int tmp = array[j];
            for (int j2 = j-1; j2 >=i; j2--) {
                array[j2+1] = array[j2];
            }
            array[i++] = tmp;
        }else{// 查找失敗
            break;
        }
    }
}


void Solution::testReOrderArray() {
    
    vector<int> array = {};
    
    for (int i = 0; i < 100000; i++) {
        array.push_back(i);
    }
    
    long beg = clock();
    reOrderArray(array, isEven);
    printf("%lf\n", double(clock() - beg) / CLOCKS_PER_SEC);
    
    array.clear();
    for (int i = 0; i < 100000; i++) {
        array.push_back(i);
    }
    
    beg = clock();
    reOrderArray2(array);
    printf("%lf\n", double(clock() - beg) / CLOCKS_PER_SEC);
    
    
//    for (auto i = 0; i < array.size(); i++) {
//        printf("%d ", array[i]);
//    }
//    printf("\n");
}



