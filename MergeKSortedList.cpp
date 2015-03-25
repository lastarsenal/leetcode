/**
 * Definition for singly-linked list.
 */
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
         return  a->val > b->val; 
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode *head = NULL;
        ListNode *prev = NULL;
        while (!pq.empty()) {
            ListNode* p = pq.top();
            if (head == NULL) {
                head = p;
            } else {
                prev->next = p;
            }
            pq.pop();
            prev = p;
            if (p->next != NULL) {
                pq.push(p->next);
            }
        }
        return head;
    }
};

int main() {
    int a[5] = {1, 3, 7, 9, 9};
    int b[3] = {2, 4, 5};
    ListNode *head1 = NULL;
    ListNode *prev = NULL;
    for (int i = 0; i < 5; i++) {
        ListNode *p = new ListNode(a[i]);
        if (i == 0) {
            head1 = p;
        } else {
            prev->next = p;
        }     
        prev = p;
    }
    ListNode *head2 = NULL;
    prev = NULL;
    for (int j = 0; j < 3; j++) {
        ListNode *p = new ListNode(b[j]);
        if (j == 0) {
            head2 = p;
        } else {
            prev->next = p;
        }     
        prev = p;
    }
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    Solution s;
    ListNode *res = s.mergeKLists(lists);    
    ListNode *p = res;
    while (p!=NULL) {
        printf("%d->", p->val);
        ListNode *temp = p;
        p = p->next;
        delete temp;
    }
    printf("\n");

}
