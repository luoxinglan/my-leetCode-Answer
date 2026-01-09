//
// Created by heihuhu on 26-1-8.
//
#include "../include/myLinkList.h"

#include <stdio.h>
#include <stdlib.h>
/**
 * 返回单链表的最后一个结点，不论是否带头结点。
 * @param l 单链表
 * @return 单链表的最后一个节点
 */
ListNode *findTail(LinkList l) {
    if (l == NULL) {
        return NULL;
    }
    if (l->next == NULL) {
        return l;
    }
    ListNode *p = l->next;
    while (p->next) {
        p = p->next;
    }
    return p;
}

/**
 * 尾插法插入单链表，每次插入会更新到最新的尾结点。
 * @param l 头结点指针。
 * @param rear 尾结点指针的指针，每次插入会更新到最新的尾结点
 * @param n 待插入的数据
 */
void tailInsert(LinkList l, ListNode **rear, int n) {
    if (l == NULL) {
        return;
    }
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->val = n;
    p->next = NULL;
    (*rear)->next = p; //注意：->成员选择运算符优先级高于*指针运算符。
    *rear = p;
}

/**
 * 初始化无头结点单链表（尾插法）。
 * @param l 单链表头结点指针
 * @param n 待插入的数据
 */
LinkList initLinkListNoHead(int n, int *nums) {
    LinkList l = (LinkList) malloc(sizeof(ListNode));
    l->next = NULL;
    ListNode *rear = findTail(l);
    for (int i = 0; i < n; i++) {
        // ListNode *p = (ListNode *) malloc(sizeof(ListNode));
        if (i == 0) {
            //是第一个结点的话不用插入。
            l->val = nums[i];
        } else {
            tailInsert(l, &rear, nums[i]);
        }
    }
    return l;
}


/**
 * 206反转链表（无头结点）。
 * @param head 首结点指针
 * @return 尾结点指针
 */
struct ListNode *reverseList206(struct ListNode *head) {
    struct ListNode *pre = NULL, *p = head, *q = NULL;
    while (p) {
        q = p->next;
        p->next = pre;
        pre = p;
        p = q;
    }
    return pre;
}

/**
 * 92反转链表 II。反转left和right中间的链表（包括）。
 * @param head 首结点指针
 * @param left 第left个结点（从1开始）
 * @param right 第right个结点（从1开始）
 * @return 反转后的链表
 */
struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    struct ListNode *pre = NULL, *p = head, *q = NULL;
    struct ListNode *h = head, *l = NULL, *r = NULL, *tail = NULL;
    for (int i = 1; i < left; i++) {
        //找到左边界
        l = p;
        p = p->next;
    }
    r = p;
    for (int i = left; i <= right; i++) {
        //找到右边界
        r = r->next;
    }
    int count = left;
    tail = p;
    while (count <= right && p) {
        q = p->next;
        p->next = pre;
        pre = p;
        p = q;
        count++;
    }
    if (tail) {
        tail->next = r;
    }
    if (l) {
        l->next = pre;
        return h;
    }
    return pre;
}

//25. K 个一组翻转链表
struct ListNode *reverseKGroup25(struct ListNode *head, int k) {
    struct ListNode *pre = NULL; //当前结点的前驱指针。每一段处理完以后总是指向这一段的首结点。
    struct ListNode *cur = head; //当前结点指针
    struct ListNode *rear = NULL; //当前结点的后继指针
    struct ListNode *resHead = head; //最终返回的链表的头结点指针
    struct ListNode *tmpTail = cur; //当前这一段的尾结点指针
    struct ListNode *preTail = NULL; //上一段的尾结点指针
    int N = 0; //统计结点个数
    while (cur) {
        N++;
        cur = cur->next;
    }
    cur = head; //初始化。
    int count = 0; //当前遍历了几个节点。
    int isHead = 0; //是否是结果的头节点。
    while (N >= k) {
        //个数不够了，跳出循环。
        while (cur && count < k) {
            rear = cur->next;
            cur->next = pre;
            pre = cur;
            cur = rear;
            count++;
        }
        if (preTail) {
            //若上一段的尾结点不为空，则指向这一段已经处理完的首结点。
            preTail->next = pre;
        }
        if (tmpTail) {
            if (!isHead) {
                resHead = pre;
                isHead = 1;
            }
            preTail = tmpTail; //更新上一段的尾结点指针
            pre = NULL; //pre指向空，使得新的一段的尾结点指向空。
        }
        tmpTail = cur; //更新尾结点。
        N -= count;
        count = 0;
    }
    if (cur) {
        //处理剩余结点
        preTail->next = cur;
    }
    return resHead;
}
