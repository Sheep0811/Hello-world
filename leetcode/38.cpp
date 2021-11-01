class Solution {
public:
    string countAndSay(int n) {
    if(n==1)return "1";
    string pre=countAndSay(n-1),ans="";
    int count=1;
    for(int i=0;i<pre.size();i++)
    {
        if(pre[i]==pre[i+1])count++;
        else
        {
            ans+=to_string(count)+pre[i];
            count=1;
        }        
    }
    return ans; 
    }
};