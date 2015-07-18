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
    ListNode* removeElements(ListNode* head, int val) {
        // find new head
        while(head != NULL)
        {
            if(head->val == val)
            {
                ListNode *temp = head->next;
                delete head;
                head = temp;
            }
            else
            {
                break;
            }
        }
        
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur !=  NULL)
        {
            if(cur->val == val)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};