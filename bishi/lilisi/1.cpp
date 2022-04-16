class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* formatList(ListNode* head) {
        // write code here
        while(head==nullptr)return nullptr;
        deque<ListNode*>tmp;
        tmp.push_back(head);
        head=head->next;
        int a=0;
        while(head!=nullptr)
        {
            if(a==0)
            {
                tmp.push_back(head);
                a=1;
            }
            else
            {
                tmp.push_front(head);
                a=0;
            }
            head=head->next;
        } 
        for(int i=0;i<tmp.size()-1;++i)
        {
            tmp[i].next=tmp[i+1];
        }
        tmp[tmp.size()-1]->next=nullptr;
        return tmp[0];
    }
};

