class Solution {
public:
    vector<string> permutation(string s) 
    {
        dfs(s,0);
        return res;
    }
private:
vector<string>res;
void dfs(string s,int x)
{
    if(x==s.size()-1)
    {
        res.push_back(s);
    }
    for(int i=x;i<s.size();i++)
    {
        bool flag=true;
        for(int j=x;j<i;j++)
        {
            if(s[i]==s[j])
            flag=false;
        }
        if(flag)
        {
            swap(s[x],s[i]);
            dfs(s,x+1);
            swap(s[x],s[i]);
        }
    }
}
};