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
    
    multiset<int> valueSet;
    long size = input.size();
    for (long i = 0; i < size; i++) {
        if (valueSet.size() < k) {
            valueSet.insert(input[i]);
        }else{
            // https://stackoverflow.com/questions/26459778/how-a-multiset-works-and-how-one-can-find-the-minimum-element-in-multiset
            multiset<int>::iterator maximum = max_element(valueSet.begin(), valueSet.end());
            if (*maximum > input[i]) {
                valueSet.erase(maximum);
                valueSet.insert(input[i]);
            }
        }
    }
    
    for (auto value: valueSet) {
        result.push_back(value);
    }
    
    return result;
}


void Solution::testLeastKNumbers() {
    
    vector<int> values = {4,5,1,6,2,7,3,8};
    
    printVector(GetLeastNumbers_Solution2(values, 4));
    
}
