/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//删除倒数第n个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
struct ListNode* pre;
struct ListNode* p;

pre=head;
p=head;  

if(!head||!head->next)
return NULL;
 
for (int i = 0; i < n; i++)            
{  
   p=p->next;
}  

if(!p)return head->next;

while(p->next)
{
pre=pre->next;
p=p->next;   
}

pre->next=pre->next->next;

return head;
}