//
//  25 FindSumPathInBTree.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/18.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

void dfs(vector<vector<int> > &result, TreeNode* node, vector<int> path, int sum, int expectSum) {
    
    if (!node) return;
    
    int newSum = node->val + sum;
    path.push_back(node->val);
//    printf("--%p, %d, %d\n", node, node->val, newSum);
    if (node->left == NULL && node->right == NULL) {
        if (newSum == expectSum) {
            vector<int> validPath(path);
            result.push_back(path);
        }
    }
    
    dfs(result, node->left, path, newSum, expectSum);
    dfs(result, node->right, path, newSum, expectSum);
    path.pop_back();
    
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    
    vector<vector<int> > result;
    vector<int> path;
    dfs(result, root, path, 0, expectNumber);
    return result;
}


vector<vector<int> > findResults;
vector<int> path;

vector<vector<int> > FindPath2(TreeNode* root,int expectNumber) {
    
    if (!root) return findResults;
    
    path.push_back(root->val);
    if (!root->left && !root->right && expectNumber == root->val) {
        findResults.push_back(path);
        path.pop_back();
        return findResults;
    }
    
    FindPath2(root->left, expectNumber - root->val);
    FindPath2(root->right, expectNumber - root->val);
    path.pop_back();
    return findResults;
}

void Solution::testFindSumPathInBTree() {
    
    TreeNode* rightTree = new TreeNode(12);
//    rightTree->left = new TreeNode(9);
//    rightTree->right = new TreeNode(12);
    
    TreeNode* leftTree = new TreeNode(5);
    leftTree->left = new TreeNode(4);
    leftTree->right = new TreeNode(7);
    
    TreeNode* tree1 = new TreeNode(10);
    tree1->left = leftTree;
    tree1->right = rightTree;
    
    vector<vector<int> > result = FindPath2(tree1, 22);
    for(auto v: result) {
        printVector(v);
    }
    
    findResults.clear();
    
    result = FindPath2(NULL, 22);
    for(auto v: result) {
        assert(false);
        printVector(v);
    }
    
    findResults.clear();
    
    result = FindPath2(rightTree, 22);
    for(auto v: result) {
        assert(false);
        printVector(v);
    }
    
    findResults.clear();
    
}
