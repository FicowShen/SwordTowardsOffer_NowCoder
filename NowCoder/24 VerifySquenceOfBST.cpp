//
//  24 VerifySquenceOfBST.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/18.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

bool checkSquecen(vector<int> sequence, int start, int end) {
    
    if (end <= start) {
        return true;
    }
    // 后序遍历，最后的值就是根
    int mid = sequence[end];
    int i = start;
    // 比根小的都位于左子树
    while (i < end && sequence[i] < mid) {
        i++;
    }
    // 比根大的都位于右子树
    int j = i;
    while (j < end) {
        // 在右子树找到比根小的值，不是BST
        if (sequence[j] < mid) {
            return false;
        }
        j++;
    }
    // 检验左子树和右子树
    return checkSquecen(sequence, start, i - 1) && checkSquecen(sequence, i, end - 1);
    
    
}

bool VerifySquenceOfBST(vector<int> sequence) {
    
    if (sequence.empty()) {
        return false;
    }
    
    return checkSquecen(sequence, 0, sequence.size() - 1);
}

void Solution::testVerifySquenceOfBST() {
    
    vector<int> sequence = {5,7,6,9,11,10,8};
    assert(VerifySquenceOfBST(sequence));
    
    sequence = {8};
    assert(VerifySquenceOfBST(sequence));
    
    sequence = {6,8};
    assert(VerifySquenceOfBST(sequence));
    
    sequence = {9,8};
    assert(VerifySquenceOfBST(sequence));
    
    sequence = {};
    assert(!VerifySquenceOfBST(sequence));
    
    sequence = {7,4,6,5};
    assert(!VerifySquenceOfBST(sequence));
    
}
