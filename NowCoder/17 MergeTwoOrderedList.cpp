//
//  17 MergeTwoOrderedList.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/1.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 合并两个有序链表（递归）
 
 @param pHead1 链表1的头结点
 @param pHead2 链表2的头结点
 @return 合并后的链表的头结点
 */
ListNode* MergeRecursively(ListNode* pHead1, ListNode* pHead2) {
    
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    
    ListNode* newHead = pHead1;
    if (pHead1->val <= pHead2->val) {
        newHead = pHead1;
        newHead->next =  MergeRecursively(pHead1->next, pHead2);
    }else{
        newHead = pHead2;
        newHead->next = MergeRecursively(pHead1, pHead2->next);
    }
    return newHead;
}


/**
 合并两个有序链表（循环）

 @param pHead1 链表1的头结点
 @param pHead2 链表2的头结点
 @return 合并后的链表的头结点
 */
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    
    ListNode* newHead = NULL;
    ListNode* p = NULL;
    ListNode* next = pHead1;
    
    while (next != NULL) {
        
        if (pHead1->val <= pHead2->val) {
            next = pHead1;
            pHead1 = pHead1->next;
        }else{
            next = pHead2;
            pHead2 = pHead2->next;
        }
        if (newHead == NULL) {
            newHead = next;
        }else{
            p->next = next;
        }
        p = next;
        next = next->next;
    }
    
    ListNode* nonEmptyHead = pHead1 == NULL ? pHead2 : pHead1;
    p->next = nonEmptyHead;
    
    return newHead;
}


void Solution::testMergeTwoOrderedList() {
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    head1->next->next->next = new ListNode(7);
    head1->next->next->next->next = new ListNode(9);
    
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);
    head2->next->next->next = new ListNode(8);
    head2->next->next->next->next = new ListNode(11);
    
    ListNode* result = MergeRecursively(head1, head2);
    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
}
