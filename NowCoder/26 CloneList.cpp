//
//  26 CloneList.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/19.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void printNodes(RandomListNode* head) {
    
    if (!head) {
        return;
    }
    
    while (head) {
        printf("%d", head->label);
        if (head->random) {
            printf(" -> %d", head->random->label);
        }
        printf("\n");
        head = head->next;
    }
    printf("------\n\n");
}

void cloneNodes(RandomListNode* pHead) {
    
    RandomListNode* p = pHead;
    
    while (p) {
        RandomListNode* temp = new RandomListNode(p->label);
        temp->next = p->next;
        p->next = temp;
        p = temp->next;
    }
    
//    printNodes(pHead);
}

void linkSiblings(RandomListNode* pHead) {
    
    RandomListNode* p = pHead;
    
    while (p) {
        if (p->random) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }
    
//    printNodes(pHead);
}

RandomListNode* detachCopiedList(RandomListNode* pHead) {
    
    RandomListNode* old = pHead;
    RandomListNode* copied = pHead->next;
    RandomListNode* p = copied;
    
    while (old) {
        old->next = old->next->next;
        old = old->next;
        if (old) {
            p->next = p->next->next;
        }
        p = p->next;
    }
    
    return copied;
}

RandomListNode* Clone(RandomListNode* pHead)
{
    if (!pHead) {
        return NULL;
    }
    cloneNodes(pHead);
    linkSiblings(pHead);
    return detachCopiedList(pHead);
}



void Solution::testCloneList() {
    
    RandomListNode* head = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    RandomListNode* node4 = new RandomListNode(4);
    RandomListNode* node5 = new RandomListNode(5);
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    head->random = node3;
    node2->random = node5;
    node4->random = node2;
    
//    printNodes(head);
    
    printNodes(Clone(head));
    
    printNodes(Clone(NULL));
    
    printNodes(Clone(node5));
    
    
}
