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

缓存了所有指针，不妥，慢

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
        ListNode* p = head;
        ListNode* q = head;
        vector<ListNode*> prevs;
        int i = 0;
        int j = 0;
        while (q!=NULL) {
            prevs.push_back(q);
            q = q->next;
            j++;
        }
        j = j - 1;
        while (i < j) {
            q = prevs[j];
            ListNode* next = p->next;
            p->next = q;
            q->next = next;
            p = next; 
            i++;
            j--;
        }
        p->next = NULL;
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
