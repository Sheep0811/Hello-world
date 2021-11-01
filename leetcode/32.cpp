class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int start=0;
        stack <int> left;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==')' && left.empty())
            {
                start=i+1;
                continue;
            } 
            if(s[i]=='(')left.push(i);
            else
            {
                if(!left.empty())
                {
                    left.pop();
                    if(left.empty()) 
                    {
                        ans=max(ans,i-start+1);
                    }
                    else
                    {
                        ans=max(ans,i-left.top());
                    }
                }
            } 
            }
        return ans;
    }
};