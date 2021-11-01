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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *q = head,p=head;
        while(k--)
        {
            q = q->next;
        }
        while(q!=nullptr)
        {
            q = q->next;
            p = p->next;
        }
        return p;
        // int count = 0;
        // while(q!=nullptr)
        // {
        //     ++count;
        //     q = q->next;
        // }
        // count -= k;
        // q = head;
        // while(count--)
        // {
        //     q = q->next;
        // }
        // return q;
    }
};