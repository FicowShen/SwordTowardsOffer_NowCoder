//
//  27 ConvertDoubleLinkedListFromBST.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/19.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

void reconnect(TreeNode* pRootOfTree, TreeNode** lastNode) {
    
    if (!pRootOfTree) {
        return;
    }
    
    if (pRootOfTree->left) {
        reconnect(pRootOfTree->left, lastNode);
    }
    
    if (*lastNode) {
        pRootOfTree->left = *lastNode;
        (*lastNode)->right = pRootOfTree;
    }
    
    *lastNode = pRootOfTree;
    
    if (pRootOfTree->right) {
        reconnect(pRootOfTree->right, lastNode);
    }
    
}

TreeNode* Convert(TreeNode* pRootOfTree) {
    
    TreeNode* lastNode = NULL;
    reconnect(pRootOfTree, &lastNode);
    
    while (lastNode && lastNode->left) {
        lastNode = lastNode->left;
    }
    
    return lastNode;
    
    
    // stack overflow 2
    
//    TreeNode* leftRoot = pRootOfTree->left;
//    if (leftRoot) {
//        TreeNode* left;
//        if (leftRoot->right) {
//            left = Convert(leftRoot->right);
//            left->left = Convert(leftRoot);
//        }else{
//            left = Convert(leftRoot);
//        }
//        pRootOfTree->left = left;
//        left->right = pRootOfTree;
//    }
//
//    TreeNode* rightRoot = pRootOfTree->right;
//    if (rightRoot) {
//        TreeNode* right;
//        if (rightRoot->left) {
//            right = Convert(rightRoot->left);
//            right->right = Convert(rightRoot);
//        }else{
//            right = Convert(rightRoot);
//        }
//        pRootOfTree->right = right;
//        right->left = pRootOfTree;
//    }
    
//    return pRootOfTree;
    
    
    // stack overflow 1
    
//    if (pRootOfTree->left) {
//        TreeNode* right = pRootOfTree->left;
//        while (right->right) {
//            right = right->right;
//        }
//        Convert(pRootOfTree->left);
//        right->right = pRootOfTree;
//        pRootOfTree->left = right;
//    }
//
//    if (pRootOfTree->right) {
//        TreeNode* left = pRootOfTree->right;
//        while (left->left) {
//            left = left->left;
//        }
//        Convert(pRootOfTree->right);
//        left->left = pRootOfTree;
//        pRootOfTree->right = left;
//    }
    
//    return pRootOfTree;
}

void printDoubleLinkList(TreeNode* node) {
    
//    while (node->left) node = node->left;
    
    while (node) {
        printf("%d ", node->val);
        node = node->right;
    }
    
    printf("\n");
}

void Solution::testConvertDoubleLinkedListFromBST() {
    
    TreeNode* rightTree = new TreeNode(14);
    TreeNode* rightTree2 = new TreeNode(12);
//    TreeNode* rightTree3 = new TreeNode(11);
    rightTree->left = rightTree2;
//    rightTree2->left = rightTree3;
    rightTree->right = new TreeNode(16);
    
    TreeNode* leftTree = new TreeNode(6);
    leftTree->left = new TreeNode(4);
    leftTree->right = new TreeNode(8);
    
    TreeNode* tree1 = new TreeNode(10);
    tree1->left = leftTree;
    tree1->right = rightTree;
    
    printDoubleLinkList(Convert(tree1));
    
    
}
