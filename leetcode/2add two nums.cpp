/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
int a1,a2,ans,flag=0;
struct ListNode *p=l1;
struct ListNode *q=l2;
struct ListNode *cur=(struct ListNode*)malloc(sizeof(struct ListNode));
cur->next=NULL;
struct ListNode *head=cur;
while(p!=NULL||q!=NULL)
{
    a1=(p!=NULL)?p->val:0;
    a2=(q!=NULL)?q->val:0;
    ans=a1+a2+flag;
    flag=ans/10;
    cur->next=(struct ListNode*)malloc (sizeof(struct ListNode));
    cur=cur->next;
    cur->val=ans%10;
    cur->next=NULL;
    if(p!=NULL)
    p=p->next;
    if(q!=NULL)
    q=q->next;
}
if(flag>0){
cur->next=(struct ListNode*)malloc(sizeof(struct ListNode));
cur=cur->next;
cur->val=0;
cur->next=NULL;
}

return head->next;
}