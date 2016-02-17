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
        
        ListNode *odd_lst_end = head;
        ListNode *even_lst_end = head->next;
        while(even_lst_end != NULL && even_lst_end->next != NULL)
        {
            ListNode *fst_even_node = odd_lst_end->next;
            ListNode *next_odd_node = even_lst_end->next;
            odd_lst_end->next = next_odd_node;
            even_lst_end->next = next_odd_node->next;
            next_odd_node->next = fst_even_node;
            
            odd_lst_end = odd_lst_end->next;
            even_lst_end = even_lst_end->next;
        }
        return head;
    }
};