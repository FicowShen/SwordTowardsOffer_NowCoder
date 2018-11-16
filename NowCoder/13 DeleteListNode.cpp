//
//  13 DeleteListNode.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/1.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

void deleteListNodeWithO1(ListNode* pListHead, ListNode* toDelete) {
    
    if (pListHead == NULL || toDelete == NULL) {
        return;
    }
    
    // 仅有一个头结点
    if (pListHead->next == NULL) {
        // 删除的就是头结点
        if (pListHead == toDelete) {
            pListHead = NULL;
        }
        return;
    }
    
    // 中间结点
    if (toDelete->next) {
        ListNode* del = toDelete->next;
        toDelete->val = del->val;
        toDelete->next = del->next;
        delete del;
        del = NULL;
        return;
    }
    
    // 尾结点
    ListNode* p = pListHead;
    while (p->next) {
        if (p->next == toDelete) {
            p->next = NULL;
            delete toDelete;
            toDelete = NULL;
            return;
        }
    }
    
}

void testDeleteListNodeWithO1() {
    
    ListNode* head = NULL;
    deleteListNodeWithO1(head, NULL);
    
    head = new ListNode(1);
    deleteListNodeWithO1(head, head);
    
    head->next = new ListNode(2);
    ListNode* mid = new ListNode(3);
    head->next->next = mid;
    
    head->next->next->next = new ListNode(4);
    ListNode* last = new ListNode(5);
    head->next->next->next->next = last;
    
    deleteListNodeWithO1(head, last);
    
    deleteListNodeWithO1(head, mid);
    
    
}
