/**
 * =====================================================================================
 *       Filename:  ReoderList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-03-12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yixun 
 *
 * =====================================================================================
 *
 */

/**
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

Hide Tags Linked List

快慢两个指针，一个走一步，一个走两步，可以找到链表的中心点。
然后从中心点开始，revert后半段链表
最后把前半段和后半段做merge。

 */
#include <vector>
#include <stdio.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        ListNode *slow = head;
        ListNode *fast = head;
        //find middle
        int i = 0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            i++;
        }
        if (i == 0) return;
        ListNode *temp = slow->next;
        slow->next = NULL;
        slow = temp;
        //revert half of tail
        ListNode *p2 = NULL;
        while (slow != NULL) {
            temp = slow->next;
            slow->next = p2;
            p2 = slow;
            slow = temp;
        }
        //merge
        ListNode *p1 = head;
        while (p1 != NULL && p2 != NULL) {
            ListNode *t1 = p1->next;
            ListNode *t2 = p2->next;
            p1->next = p2;
            p2->next = t1;
            p1 = t1;
            p2 = t2;
        }
    }
};

int main() {
    int a[4] = {1,2,3,4};
    ListNode *prev = NULL;
    ListNode *head = NULL;
    for (int i = 0; i < 4; i++) {
        ListNode *curr = new ListNode(a[i]);
        if (prev) {
            prev->next = curr;
        } else {
            head = curr;
        }
        prev = curr;
    }
    Solution s;
    s.reorderList(head);
    ListNode *p = head;
    while (p!=NULL) {
        printf("%d->", p->val);
        ListNode *q = p->next;
        delete p;
        p = q;
    }
    printf("\n");
}
