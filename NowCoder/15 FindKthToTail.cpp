//
//  15 FindKthToTail.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/1.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 查找链表中的倒数第K个结点

 @param pListHead 链表
 @param k K
 @return 查找到的结点
 */
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    
    if (pListHead == NULL || k == 0) {
        return NULL;
    }
    
    ListNode* pre = pListHead;
    for (int i = 1 ; i < k; i++) {
        if (pre->next) {
            pre = pre->next;
        }else{
            return NULL;
        }
    }
    
    ListNode* post = pListHead;
    while (pre->next) {
        pre = pre->next;
        post = post->next;
    }
    
    return post;
}

void Solution::testFindKthToTail() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode* result = FindKthToTail(head, 1);
    printf("%d\n", result->val);
    
}
