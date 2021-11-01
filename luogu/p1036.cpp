#include<bits/stdc++.h>
using namespace std;
int ans=0;
int a[25];
int k,n;
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int m,int sum,int start)
{
    if(m==k)
    {
        if(isprime(sum))
        ans++;
    }
    for(int i=start;i<n;i++)
    {
        dfs(m+1,sum+a[i],i+1);
    }
}
int main()
{
    cin>>n>>k;
    for(int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    dfs(0,0,0);
    printf("%d",ans);
    system ("pause");
    return 0;
}