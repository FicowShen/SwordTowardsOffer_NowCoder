//
//  4 ReConstructBinaryTree.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/25.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 重建二叉树

 @param pre 先序序列
 @param pre_start 先序的开始位置
 @param pre_end 先序的结束位置
 @param vin 中序序列
 @param vin_start 中序的开始位置
 @param vin_end 中序的结束位置
 @return 重建后的二叉树
 */
TreeNode* constructBinaryTree(vector<int> pre, long pre_start, long pre_end, vector<int> vin, long vin_start, long vin_end) {
    
    TreeNode *root_node = NULL;
    
    if (pre_start == 0) {
        
        int root = pre[0];
        root_node = new TreeNode(root);
        
        long root_index = -1;
        for (long i = vin.size() - 1; i >= 0 ; i--) {
            if (vin[i] == root) {
                root_index = i;
                break;
            }
        }
        if (root_index == -1) {
            return NULL;
        }
        
        root_node->left = constructBinaryTree(pre, 1, root_index, vin, 0, root_index - 1);
        root_node->right = constructBinaryTree(pre, root_index + 1, pre.size() - 1, vin, root_index + 1, vin.size() - 1);
    }else {
        
//        printf("--%d,%d,%d,%d\n", pre_start, pre_end, vin_start, vin_end);
        
        if (pre_start <= pre_end && vin_start <= vin_end) {
            
            int root = pre[pre_start];
            root_node = new TreeNode(root);
            
            long root_index = -1;
            for (long i = vin_end; i >= vin_start ; i--) {
                if (vin[i] == root) {
                    root_index = i;
                    break;
                }
            }
            if (root_index == -1) {
                return NULL;
            }
            
            long left_pre_end = pre_start + root_index - vin_start;
            root_node->left = constructBinaryTree(pre, pre_start + 1, left_pre_end, vin, vin_start, root_index - 1);
            root_node->right = constructBinaryTree(pre, left_pre_end + 1, pre_end, vin, root_index + 1, vin_end);
        }
    }
    
    return root_node;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    
    if (pre.empty() || vin.empty() || pre.size() != vin.size()) {
        return NULL;
    }
    
    return constructBinaryTree(pre, 0, 0, vin, 0, 0);
}



void Solution::testReConstructBinaryTree() {
    
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    TreeNode* head = reConstructBinaryTree(pre, vin);
    
    printTree(head);
}
