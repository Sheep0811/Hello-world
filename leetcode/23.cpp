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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(list.empty())return nullptr;
        int n=lists.size();
        listNode ans=lists[0];
        for(int i=1;i<n;i++) 
        {
            ans=merge(ans,lists[i]);
        }
        return ans;
    }
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* root=new ListNode(0),pre=root;
        while(a && b)
        {
            if(a->val<b->val)
            {
                pre->next=a;
                a=a->next;
            }
            else
            {
                pre->next=b;
                b=b->next;
            }
            pre=pre->next;
        }
        pre->next=a?a:b;
        return root->next;
    } 

};