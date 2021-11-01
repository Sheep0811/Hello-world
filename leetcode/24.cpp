/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
if(!head||!head->next)return head;
struct ListNode* q=head->next;
head->next=swapPairs(q->next);
q->next=head;
return q;
}