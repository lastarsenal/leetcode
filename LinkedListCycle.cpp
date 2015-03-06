/**
 * =====================================================================================                                                                                                                                                    
 *
 *       Filename:  WordSearch.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Hide Tags Linked List Two Pointers

解题思路：
判断链表上是否有环视经典题，设置两个指针，初始化都在头部，然后一个走一步，一个走两步，如果相遇则有环，如果碰到NULL，则链表可以到达结尾，无环
 */
#include <stdio.h> 
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == NULL) {
                break;
            }
            p2 = p2->next;
            if (p1 && p2 && p1 == p2) {
                return true;
            }
        }    
        return false;
    }
};
