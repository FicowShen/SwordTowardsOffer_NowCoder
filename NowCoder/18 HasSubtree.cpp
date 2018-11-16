//
//  18 HasSubtree.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/2.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"


/**
 校验树的子结构

 @param pRoot1 树
 @param pRoot2 子树
 @return 树是否包含子树
 */
bool findSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
    
    // 子树遍历结束
    if (!pRoot2) return true;
    // 不包含子树结点
    if (!pRoot1) return false;
    // 结点的值不相等
    if (pRoot1->val != pRoot2->val) return false;
    
//    // 遍历左右结点
//    if (!findSubTree(pRoot1->left, pRoot2->left)) {
//        return false;
//    }
//    if (!findSubTree(pRoot1->right, pRoot2->right)) {
//        return false;
//    }
//    return true;
    return findSubTree(pRoot1->left, pRoot2->left)
    && findSubTree(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    
    // 空树
    if (!pRoot1 || !pRoot2) return false;
//    // 判断是否相等
//    if (findSubTree(pRoot1, pRoot2)) {
//        return true;
//    }
//    // 遍历左右结点
//    if (HasSubtree(pRoot1->left, pRoot2)) {
//        return true;
//    }
//    if (HasSubtree(pRoot1->right, pRoot2)) {
//        return true;
//    }
//    return false;
    
    return findSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

void Solution::testHasSubtree() {
    
    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(4);
    root3->right = new TreeNode(7);
    
    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(9);
    root2->right = root3;
    
    TreeNode* tree1 = new TreeNode(8);
    tree1->left = root2;
    tree1->right = new TreeNode(7);
    
    TreeNode* tree2 = new TreeNode(8);
    tree2->left = new TreeNode(9);
    tree2->right = new TreeNode(2);
    
    printf("%d\n", HasSubtree(tree1, tree2));
    printf("%d\n", HasSubtree(NULL, NULL));
    printf("%d\n", HasSubtree(tree1, NULL));
    printf("%d\n", HasSubtree(NULL, tree2));
    
}
