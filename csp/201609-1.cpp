#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,ans=0;
    cin>>a;
    for(int i=0;i<n-1;i++)
    {
        int tmp;
        cin>>tmp;
        if(abs(tmp-a)>ans)ans=abs(tmp-a);
        a=tmp;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}