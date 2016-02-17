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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode *odd_lst = head;
        ListNode *even_lst = NULL;
        ListNode *cur_node = head->next;
        ListNode *cur_odd_node = head;
        ListNode *cur_even_node = NULL;
        int32_t idx = 2;
        while(cur_node != NULL)
        {
            if(idx++ & 1)
            {
                cur_odd_node->next = cur_node;
                cur_odd_node = cur_node;
            }
            else
            {
                if(even_lst == NULL)
                {
                    even_lst = cur_node;
                    cur_even_node = cur_node;
                }
                else
                {
                    cur_even_node->next = cur_node;
                    cur_even_node = cur_node;
                }
            }
            cur_node = cur_node->next;
        }
        cur_odd_node->next = even_lst;
        if(cur_even_node != NULL)
        {
            cur_even_node->next = NULL;
        }
        return head;
    }
};