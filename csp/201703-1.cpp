#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int ca[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>ca[i];
    }
    //sort(ca,ca+n);
    int count=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        count+=ca[i];
        if(count>=k){
            ans++;
            count=0;
        }
}
if(count!=0)ans++;
cout<<ans<<endl;
    system("pause");
    return 0;
}