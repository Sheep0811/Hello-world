#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    int n,x,ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        q.push(x);
    }
    while(q.size()>=2)
    {
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    printf("%d",ans);
    system("pause");
    return 0;
}