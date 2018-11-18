//
//  1 Find.hpp
//  NowCoder
//
//  Created by Ficow on 2018/10/24.
//  Copyright © 2018 ficow. All rights reserved.
//

#ifndef __Find_hpp
#define __Find_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "Solution.hpp"

#define re(i, n) for (int i=0; i<n; i++)

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    // 25，二叉树中和为某一值的路径
    void testFindSumPathInBTree();
    
    // 24，验证二叉搜索树的后序遍历序列
    void testVerifySquenceOfBST();
    
    // 23，从上往下按层打印二叉树结点
    void testPrintTreeFromTopToBottom();
    
    // 22，栈的压入与弹出序列
    void testCheckStackPushPopOrder();
    
    // 21，包含min函数的栈
    void testStackWithMinFunction();
    
    // 20，顺时针打印矩阵
    void testPintMatrix();
    
    // 19，二叉树的镜像
    void testMirror();
    
    // 18, 树的子结构
    void testHasSubtree();
    
    // 17，合并两个有序链表
    void testMergeTwoOrderedList();
    
    // 16，反转链表
    void testReverseList();
    
    // 15，查找链表中的倒数第K个结点
    void testFindKthToTail();
    
    // 14，将数组中的奇数置于偶数前面
    void testReOrderArray();
    
    // 13，在O(1)时间删除结点
    void testDeleteListNodeWithO1();
    
    // 12， 打印从1到最大N位数的递增排列
    void testPrintOneToMaxNDigits();
    
    // 11，实现库函数pow的功能
    void testPower();
    
    // 10，统计一个数的二进制中有多少个1
    void testNumberOf1();
    
    // 9，求n的斐波那锲数
    void testFibonacci();
    
    // 8，已排序数组在被旋转后，找到其中最小元素
    void testMinNumberInRotateArray();
    
    // 7，两个栈模拟一个队列
    void testMakeQueueWithTwoStack();
    
    // 6，重建二叉树
    void testReConstructBinaryTree();
    
    // 5，反向输出链表的值
    void testPrintListFromTailToHead();
    
    // 4，替换空格
    void testReplaceSpace();
    
    // 3，找出二维数组(从左至右递增、从上至下递增)中是否存在某个值
    void testFind();
    
    // 0，快速排序
    void testQuickSort();
    
    
};

/**
 线程睡眠
 
 @param nanoSeconds 纳秒数(0~999999999)，默认为5e8，即半秒
 @param seconds 秒数(非负)
 */
void sleep(int nanoSeconds = 5e8, int seconds = 0);

void printTree(TreeNode* node);

template<typename T>
void printVector(const vector<T>& v);

#endif /* __Find_hpp */
