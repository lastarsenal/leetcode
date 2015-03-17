/**
 * =====================================================================================
 *       Filename:  IntersectionOfTwoLinkedLists.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Hide Tags Linked List

解题思路：先遍历两个链表，得到长度分别为m和n，设n>m，然后将长的链表先走n-m步，同时移动指针，有相同的指针则找到交点
 */

#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i = 0;
        int j = 0;
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != NULL) {
            i++;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            j++;
            p2 = p2->next;
        } 
        ListNode *pLong = i < j ? headB : headA;
        ListNode *pShort = i < j ? headA : headB;
        int step = i < j ? j - i : i - j;
        for (int k = 0; k < step; k++) {
            pLong = pLong->next;
        }
        while (pLong != NULL && pShort != NULL) {
            if (pLong == pShort) {
                return pLong;
            }
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return NULL;
    }
};


