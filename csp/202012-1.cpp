#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,score;
    int ans=0,w;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>w>>score;
       ans+=score*w; 
    }
    ans=max(0,ans);
    cout<<ans<<endl;
    system("pause");
    return 0;
}