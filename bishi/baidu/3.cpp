#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
unordered_set<string> sett;
void dfs(string a);
int main()
{
    string a;
    cin>>a;
    dfs(a);
    cout<<sett.size()%mod;
    system("pause");
    return 0;
}
void dfs(string a)
{
    if(a.size()==0)return;
    if(sett.find(a)==sett.end())sett.insert(a);
    for(int i=0;i<a.size();++i)
    {
        if(i==0)
        {
            if(a[i]<=a[i+1])dfs(a.substr(1,a.size()-1));
        }
        else if(i==a.size()-1)
        {
            if(a[i]<=a[i-1])dfs(a.substr(0,a.size()-1));
        }
        else if(a[i]<=a[i-1] || a[i]<=a[i+1])
        {
            dfs(a.substr(0,i)+a.substr(i+1,a.size()-i-1));
        } 
    }
}