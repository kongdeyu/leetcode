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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        ListNode *nodeA = headA;
        while(nodeA != NULL)
        {
            lengthA++;
            nodeA = nodeA->next;
        }
        
        int lengthB = 0;
        ListNode *nodeB = headB;
        while(nodeB != NULL)
        {
            lengthB++;
            nodeB = nodeB->next;
        }
        
        ListNode *longerlst = headA;
        ListNode *shorterlst = headB;
        int difference = lengthA - lengthB;
        if(lengthA < lengthB)
        {
            longerlst = headB;
            shorterlst = headA;
            difference = lengthB - lengthA;
        }
        
        for(int i = 0; i < difference; i++)
        {
            longerlst = longerlst->next;
        }
        
        while(longerlst != NULL)
        {
            if(longerlst == shorterlst)
            {
                return longerlst;
            }
            longerlst = longerlst->next;
            shorterlst = shorterlst->next;
        }
        return NULL;
    }
};