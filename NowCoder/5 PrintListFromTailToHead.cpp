//
//  3 PrintListFromTailToHead.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/24.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"


/**
 反向输出链表的值

 @param head 链表头指针
 @return 反向输出链表的值
 */
vector<int> printListFromTailToHead(ListNode* head) {
    
    vector<int> res = vector<int>();
    if (!head) return res;
    
    ListNode* p = head;
    while (p) {
        res.insert(res.begin(), p->val);
        p = p->next;
    }
    
    return res;
}

void Solution::testPrintListFromTailToHead() {
    
    ListNode l1 = ListNode(1);
    ListNode* head = &l1;
    
    ListNode l2 = ListNode(2);
    l1.next = &l2;
    
    ListNode l3 = ListNode(3);
    l2.next = &l3;
    
    vector<int> res = printListFromTailToHead(head);
    
    for (auto it = res.begin(); it != res.end(); it++) {
        cout<<*it;
    }
    
    cout<<endl;
}
