/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> ans;
    vector<int> reversePrint(ListNode *head)
    {
        put(head);
        return ans;
        // 辅助栈：
        //    vector<int>ans;
        //    stack<int> res;
        //    ListNode *p=head;
        //    while(p->next!=NULL)
        //    {
        //        res.push(p->val);
        //        p=p->next;
        //    }
        //    res.push(p->val);
        //    while(!res.empty())
        //    {
        //        ans.push_back(res.top());
        //        res.pop();
        //    }
        //    return ans;
    }
};