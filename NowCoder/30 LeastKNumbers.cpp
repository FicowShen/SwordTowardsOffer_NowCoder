//
//  30 LeastKNumbers.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/30.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"
#include <cstdlib>
#include <set>

int random(int min, int max) {
    int output = min + (rand() % int(max - min + 1));
    return output;
}

int partition(vector<int> &values, int start, int end) {
    
    // 随机选取一个数，移至尾部，用于比较和分隔其他数
    int index = random(start, end);
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

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    
    if (k == input.size()) return input;
    
    vector<int> result;
    
    if (k > input.size()) return result;
    
    int index = partition(input, 0, input.size() - 1);
    int start = 0, end = input.size() - 1;
    while (index != k) {
        if (index > k - 1) {
            end = index - 1;
        }else{
            start = index + 1;
        }
        index = partition(input, start, end);
    }
    for (int i = 0; i < k; i++) {
        result.push_back(input[i]);
    }
    return result;
}

vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
    
    if (k == input.size()) return input;
    
    vector<int> result;
    
    if (k > input.size()) return result;
    long size = input.size();
    
//    multiset<int> valueSet;
//    for (long i = 0; i < size; i++) {
//        if (valueSet.size() < k) {
//            valueSet.insert(input[i]);
//        }else{
//            // https://stackoverflow.com/questions/26459778/how-a-multiset-works-and-how-one-can-find-the-minimum-element-in-multiset
//            multiset<int>::iterator maximum = max_element(valueSet.begin(), valueSet.end());
//            if (*maximum > input[i]) {
//                valueSet.erase(maximum);
//                valueSet.insert(input[i]);
//            }
//        }
//    }

    multiset<int, greater<int>> valueSet;
    for (long i = 0; i < size; i++) {
        if (valueSet.size() < k) {
            valueSet.insert(input[i]);
        }else{
            if (*valueSet.begin() > input[i]) {
                valueSet.erase(valueSet.begin());
                valueSet.insert(input[i]);
            }
        }
    }
    
    for (auto value: valueSet) {
        result.push_back(value);
    }
    
    return result;
}

const int TestLoop = 100000;

void testFunc1() {
    
    vector<int> values;
    for (int i = 0 ; i < TestLoop; i++) {
        values.push_back(int(arc4random_uniform(TestLoop)));
    }
    GetLeastNumbers_Solution(values, TestLoop >> 1);
}

void testFunc2() {
    
    vector<int> values;
    for (int i = 0 ; i < TestLoop; i++) {
        values.push_back(int(arc4random_uniform(TestLoop)));
    }
    GetLeastNumbers_Solution2(values, TestLoop >> 1);
}

void Solution::testLeastKNumbers() {
    
    multiset<int, greater<int>> greadterSet;
    multiset<int, less<int>> lessSet;
    multiset<int> defaultSet;
    for (int i = 0; i < 10; i++) {
        int v = int(arc4random_uniform(10));
        greadterSet.insert(v);
        lessSet.insert(v);
        defaultSet.insert(v);
    }
    for (auto v: greadterSet) {
        printf("%d ", v);
    }
    printf("\n");
    for (auto v: lessSet) {
        printf("%d ", v);
    }
    printf("\n");
    for (auto v: defaultSet) {
        printf("%d ", v);
    }
    printf("\n");
    
    
    
    vector<int> values = {4,5,1,6,2,7,3,8};
    printVector(GetLeastNumbers_Solution2(values, 4));
    
    values = {4,5,1,6};
    printVector(GetLeastNumbers_Solution2(values, 4));
    
    values = {1,6,2};
    printVector(GetLeastNumbers_Solution2(values, 4));
    
    values = {4};
    printVector(GetLeastNumbers_Solution2(values, 0));

    benchmark(testFunc1);
    benchmark(testFunc2);
}
