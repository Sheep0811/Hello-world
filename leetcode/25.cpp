/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)return NULL;
        ListNode *a=head;
        ListNode *b=head;
        for(int i=0;i<k;i++)
        {
            if (k==NULL)return head;
            b=b->next;
        }
        ListNode *newNode=rever(a,b);
        a->next=reverseKGroup(b,k);
        return newNode;
    }
    ListNode* rever(ListNode *a, ListNode *b)
    {
        ListNode *pre=nullptr,*nxt=a,*cur=a;
        while(cur!=b)
        {
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
};