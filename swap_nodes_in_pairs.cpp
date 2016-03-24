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
        
        ListNode *new_head = head->next;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(true)
        {
            ListNode *next = cur->next;
            if(next == NULL)
            {
                pre->next = NULL;
                cur->next = pre;
                break;
            }
            
            if(next->next == NULL)
            {
                pre->next = next;
                cur->next = pre;
                break;
            }
            
            pre->next = next->next;
            cur->next = pre;
            
            cur = pre->next;
            pre = next;
        }
        return new_head;
    }
    
};