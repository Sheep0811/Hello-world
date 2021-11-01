#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    ans+=n/50*7;
    n=n%50;
    ans+=n/30*4;
    n=n%30;
    ans+=n/10;
    cout<<ans<<endl;
    system("pause");
    return 0;
}