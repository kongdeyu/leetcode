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
        
        ListNode *pre_node = head;
        ListNode *cur_node = head->next;
        if(pre_node == cur_node)
        {
            return true;
        }
        
        head->next = NULL;
        while(cur_node != NULL)
        {
            ListNode *next_node = cur_node->next;
            if(next_node == head)
            {
                return true;
            }
            cur_node->next = pre_node;
            pre_node = cur_node;
            cur_node = next_node;
        }
        return false;
    }
};