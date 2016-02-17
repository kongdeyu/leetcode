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
        ListNode *even_lst = head->next;
        ListNode *cur_odd_node = head;
        ListNode *cur_even_node = head->next;
        while(cur_even_node != NULL && cur_even_node->next != NULL)
        {
            cur_odd_node->next = cur_even_node->next;
            cur_odd_node = cur_odd_node->next;
            cur_even_node->next = cur_even_node->next->next;
            cur_even_node = cur_even_node->next;
        }
        cur_odd_node->next = even_lst;
        return head;
    }
};