//
//  16 ReverseList.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/1.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

// MARK: - 反转链表（循环）

ListNode* ReverseList(ListNode* pHead) {
    
    // 0或1个结点
    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }
    
    // 以中间的指针为基准
    ListNode* cur = pHead;
    ListNode* pre = NULL;
    ListNode* next = NULL;
    
    while (cur) {
        next = cur->next;
        cur->next = pre;
        if (next == NULL) {
            break;
        }
        pre = cur;
        cur = next;
    }
    return cur;
    
//    // 以最前的指针为基准
//    ListNode *pre = pHead->next;
//    pHead->next = NULL;
//
//    while (pre->next) {
//        ListNode* cur = pre;
//        pre = pre->next;
//        cur->next = pHead;
//        pHead = cur;
//
//    }
//
//    pre->next = pHead;
//    pHead = pre;
//
//    return pre;
}


// MARK: - 反转链表（递归）

ListNode* reverse(ListNode* pHead, ListNode* pre) {
    
    ListNode* next = pHead->next;
    pHead->next = pre; // 结点顺序反向
    if (next == NULL) { //已到尾部
        return pHead;
    }
    
    return reverse(next, pHead); // 右移
}

ListNode* ReverseListRecursively(ListNode* pHead) {
    
    if (pHead == NULL) {
        return pHead;
    }
    
    return reverse(pHead, NULL);
}


void Solution::testReverseList() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
//    ListNode* result = ReverseList(head);
    ListNode* result = ReverseListRecursively(head);
    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    
}
