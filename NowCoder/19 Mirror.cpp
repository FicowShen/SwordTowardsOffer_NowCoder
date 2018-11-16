//
//  19 Mirror.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/2.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 二叉树的镜像(BFS)
 
 @param pRoot 二叉树的根
 */
void Mirror(TreeNode *pRoot) {
    
    if (!pRoot) return;
    
    queue<TreeNode*> q;
    q.push(pRoot);
    
    while (!q.empty()) {
        TreeNode * root = q.front();
        swap(root->left, root->right);
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
        q.pop();
    }
}

/**
 二叉树的镜像（DFS）

 @param pRoot 二叉树的根
 */
void MirrorRecursively(TreeNode *pRoot) {
    if(pRoot){
        swap(pRoot->left, pRoot->right);
        MirrorRecursively(pRoot->left);
        MirrorRecursively(pRoot->right);
    }

//    if (!pRoot) return;
//    TreeNode *left = pRoot->left;
//    pRoot->left = pRoot->right;
//    pRoot->right = left;
//    MirrorRecursively(pRoot->left);
//    MirrorRecursively(pRoot->right);
}

void Solution::testMirror() {
    
    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(4);
    root3->right = new TreeNode(7);
    
    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(9);
    root2->right = root3;
    
    TreeNode* tree1 = new TreeNode(8);
    tree1->left = root2;
    tree1->right = new TreeNode(7);
    
    // 8 8 9 2 4 7 7
//    printTree(tree1);
    
    Mirror(tree1);
    
    // 8 7 8 2 7 4 9
    printTree(tree1);
}
