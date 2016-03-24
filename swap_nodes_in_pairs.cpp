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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *new_head = head->next->next;
        ListNode *cur_head = head->next;
        head->next->next = head;
        head->next = swapPairs(new_head);
        return cur_head;
    }
    
};