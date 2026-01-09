//
// Created by heihuhu on 26-1-8.
//

#ifndef MYLINKLIST_H
#define MYLINKLIST_H

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode, *LinkList;

ListNode *findTail(LinkList l);

void tailInsert(LinkList l, ListNode **rear, int n);

LinkList initLinkListNoHead(int n, int *nums);

struct ListNode *reverseList206(struct ListNode *head);

struct ListNode *reverseBetween(struct ListNode *head, int left, int right);

struct ListNode *reverseKGroup25(struct ListNode *head, int k);
#endif //MYLINKLIST_H
