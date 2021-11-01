#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int r,g,y;
    cin>>r>>y>>g;
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        switch(a){
            case 0:
            ans+=b;
            break;
            case 1:
            ans+=b;
            break;
            case 2:
            ans+=b+r;
            case 3:
            break;
        }
    }
    cout<<ans<<endl;
    system("pause") ;
    return 0;
}