//
//  Solution.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/29.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 线程睡眠
 
 @param nanoSeconds 纳秒数(0~999999999)，默认为5e8，即半秒
 @param seconds 秒数(非负)
 */
void sleep(int nanoSeconds, int seconds) {
    if (seconds < 0) {
        throw "seconds Must be Non-Negative";
    }
    if (nanoSeconds < 0 || nanoSeconds > 1e10-1) {
        throw "nanoSeconds Must be in range of 0 to 999999999";
    }
    timespec t = timespec();
    t.tv_sec = seconds;
    t.tv_nsec = nanoSeconds;
    nanosleep(&t, NULL);
}

void printTree(TreeNode* node) {
    
    if (!node) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->val);
    printTree(node->right);
}


// 函数模板需要进行全特化（特殊处理）
template<>
void printVector(const vector<int>& v) {
    
    for (auto element: v) {
        cout << element << " ";
    }
    cout << endl;
}

template<>
void printVector(const vector<string>& v) {
    
    for (auto element: v) {
        cout << element << " ";
    }
    cout << endl;
}


void benchmark(void(*block)(void)) {
    
    double start = clock();
    block();
    printf("benchmark: %.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
}
