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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        
        int length = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur->next)
        {
            length++;
        }
        
        ListNode *left = NULL;
        ListNode *right = head;
        for(int i = 0; i < length / 2; i++)
        {
            left = right;
            right = right->next;
        }
        left->next = NULL;
        left = head;
        
        right = reverse_list(right);
        while(left != NULL)
        {
            if(left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
    
    ListNode *reverse_list(ListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode *cur = head;
        ListNode *pre = NULL;
        while(cur != NULL)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};