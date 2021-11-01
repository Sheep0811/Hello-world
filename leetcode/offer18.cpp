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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p = head ,*q=p->next;
        if(p->val==val)
            return q;
        while(q->val!=val)
       {
           p = p->next;
           q = q->next;
       }
       p->next = q->next;
       return head;
    }
};