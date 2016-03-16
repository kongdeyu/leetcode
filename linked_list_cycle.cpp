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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return false;
        }
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast != NULL && slow != NULL)
        {
            if(fast == slow)
            {
                return true;
            }
            if(fast->next != NULL)
            {
                fast = fast->next->next;
            }
            else
            {
                return false;
            }
            
            slow = slow->next;
        }
        return false;
    }
};