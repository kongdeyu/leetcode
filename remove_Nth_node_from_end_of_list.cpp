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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        for(int i = 0; i < n - 1; i++)
        {
            if(fast->next == NULL)
            {
                return NULL;
            }
            fast = fast->next;
        }
        
        ListNode *slow = head;
        ListNode *pre = NULL;
        while(fast->next != NULL)
        {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }
        
        if(pre == NULL)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            pre->next = slow->next;
            delete slow;
        }
        
        return head;
    }
};