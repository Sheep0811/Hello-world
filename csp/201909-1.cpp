#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int nums=0,k,ans=0;
    for(int i=0;i<n;i++){
        int count=0;int all=0;
       cin>>count; 
       for(int j=0;j<m;j++){
           int a;
           cin>>a;
           count+=a;
           all+=a;
       }
       ans+=count;
       if(all<nums){
           nums=all;
           k=i+1;
       }
    }
    cout<<ans<<" "<<k<<" "<<(0-nums)<<endl;
    system("pause");
    return 0;
}