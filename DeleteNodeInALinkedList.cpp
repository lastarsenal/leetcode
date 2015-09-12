/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        ListNode* prev = node;
        while (node->next != NULL) {
            ListNode* tmp = node;
            node = node->next;
            tmp->val = node->val;
            prev = tmp;
        }
        prev->next = NULL;   
    }
};
