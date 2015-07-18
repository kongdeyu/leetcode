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
        if(node == NULL || node->next == NULL)
        {
            return;
        }
        
        ListNode *cur = node;
        ListNode *next = node->next;
        while(next->next != NULL)
        {
            cur->val = next->val;
            cur = next;
            next = next->next;
        }
        cur->val = next->val;
        cur->next = NULL;
        delete next;
    }
};