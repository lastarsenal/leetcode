#include <stdio.h>

/**
 * =====================================================================================
 *       Filename:  ReverseLinkedListII.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

Hide Tags Linked List

 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p = head;
        ListNode *prev_mp = NULL;
        ListNode *mp = NULL;
        ListNode *static_mp = NULL;
        for (int i = 0; i < n && p != NULL; i++) {
            if (i == m-2) {
                prev_mp = p;
            } else if (i == m-1) {
                mp = p;
                static_mp = p;
            } else if (i > m - 1) {
                if (prev_mp) {
                    prev_mp->next = p;
                } else {
                    head = p;
                }
                ListNode *temp = p->next;
                p->next = static_mp;
                static_mp = p;
                mp->next = temp;
                p = mp;
            }
            p = p->next;
        }
        return head;      
    }
};

int main() {
    ListNode head = ListNode(3);
    ListNode p = ListNode(5);
    head.next = &p;
    Solution s;
    ListNode* new_head = s.reverseBetween(&head, 1, 2);
    while (new_head) {
        printf("%d->", new_head->val);
        new_head = new_head->next;
    }
    printf("\n");
}
