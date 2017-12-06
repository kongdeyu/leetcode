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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;
        while (true) {
            if (l1 == NULL && l2 == NULL) {
                break;
            }

            int left = 0;
            int right = 0;
            if (l1 != NULL) {
                left = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                right = l2->val;
                l2 = l2->next;
            }

            int temp = left + right + carry;
            tail->next = new ListNode(temp % 10);
            tail = tail->next;
            carry = temp / 10;
        }
        if (carry == 1) {
            tail->next = new ListNode(1);
        }

        ListNode *res = head->next;
        delete head;
        return res;
    }
};
