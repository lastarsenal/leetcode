/**
 * =====================================================================================
 *       Filename:  AddTwoNumbers.cpp
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

Problem: Add Two Numbers
 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Tags Linked List Math
解题思路：
两个数相加，两个数分别用链表的形式存储，倒序。比如上例就是342+465=807，最后的和的形式也倒序。
两个链表同步遍历，相加，注意进位，以及最后结尾的进位即可。
这题可以理解为两个大整数相加的运算。
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *prev = NULL;
        ListNode *head = NULL;
        int overflow = 0;
        while (l1 != NULL || l2 != NULL) {
            int val1 = l1 == NULL ? 0 : l1->val;
            int val2 = l2 == NULL ? 0 : l2->val;
            int val = val1 + val2 + overflow;
            ListNode *node = new ListNode(val % 10);
            if (prev) {
                prev->next = node;
            } else {
                head = node;
            }
            prev = node;
            overflow = val / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (overflow > 0) {
            ListNode *node = new ListNode(overflow);
            prev->next = node;
        } 
        return head;   
    }
};
