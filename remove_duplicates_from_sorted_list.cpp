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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *p_slow = head;
        ListNode *p_fast = head->next;
        while(p_fast != NULL)
        {
            if(p_slow->val != p_fast->val)
            {
                p_slow = p_fast;
                p_fast = p_fast->next;
            }
            else
            {
                ListNode *temp = p_fast;
                p_fast = p_fast->next;
                p_slow->next = p_fast;
                delete temp;
            }
        }
        return head;
    }
};