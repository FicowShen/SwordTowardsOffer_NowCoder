//
//  23 PrintTreeFromTopToBottom.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/16.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

vector<int> PrintFromTopToBottom(TreeNode* root) {
    
    vector<int> v;
    if (root == NULL) {
        return v;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* val = q.front();
        q.pop();
        v.push_back(val->val);
        if (val->left) {
            q.push(val->left);
        }
        if (val->right) {
            q.push(val->right);
        }
    }
    
    return v;
}


void Solution::testPrintTreeFromTopToBottom() {
    
    TreeNode* rightTree = new TreeNode(10);
    rightTree->left = new TreeNode(9);
    rightTree->right = new TreeNode(11);
    
    TreeNode* leftTree = new TreeNode(6);
    leftTree->left = new TreeNode(5);
    leftTree->right = new TreeNode(7);
    
    TreeNode* tree1 = new TreeNode(8);
    tree1->left = leftTree;
    tree1->right = rightTree;
    
    vector<int> result = PrintFromTopToBottom(tree1);
    printVector(result);
    
    result = PrintFromTopToBottom(NULL);
    printVector(result);
    
    
    tree1 = new TreeNode(8);
    result = PrintFromTopToBottom(tree1);
    printVector(result);
}
