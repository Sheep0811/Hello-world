#include<bits/stdc++.h>
using namespace std;
map<int,int>x;
int main()
{
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    long long ans=0;
    int i,j;
    int x1,y1;
    for( i=0;i<a;i++){
       cin>>x1>>y1;
       x[x1]=y1;
    }
    for(j=0;j<b;j++){
       cin>>x1>>y1;
        if(x[x1]!=0)ans+=x[x1]*y1;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}