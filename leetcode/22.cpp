class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int l=0,r=0;
        vector <string> ans;
        dfs(n,"",l,r,ans);
        return ans;
    }
    void dfs(int n,string s,int l,int r,vector<string>&ans)
    {
        if(rc>lc || lc>n || rc>n)return;
       if(lc==rc && lc==n)
       {
           ans.push_back(s);
           return;
       } 
       dfs(n,s+'(',l+1,r,ans);
       dfs(n,s+')',l,r+1,ans);
    }
};