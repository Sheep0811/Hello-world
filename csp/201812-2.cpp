#include<bits/stdc++.h>
using namespace std;
int r,y,g;
int time(int l,int b,long long t){
    if(l==1){
        t=t%(r+y+g);
        if(t<=b)return b-t;
        else
        {
        t=t-b;
        if(t<=g)return 0;
        if(t>g && t<=g+y)return g+y-t+r;
        if(t>g+y)return r-t+g+y;
        }
    }   
    if(l==2){
        t=t%(r+y+g);
        if(t<=b)return b-t+r;
        else{
        t=t-b;
        if( t<=r){
            return r-t;
        }
        if(t>r && t<=r+g)return 0;
        if(t>r+g) return y-t+r+g+r;
        }
   }
    if(l==3){
        t=t%(r+y+g);
        if(t<=b)return 0;
        else
        {
        t=t-b;
        if(t<=y) return y-t+r;
        if(t>y && t<=r+y) return r-t+y;
        if(t>r+y) return 0;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>r>>y>>g>>n;
    long long ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a==0){
            ans+=b;
        }
        else {
            ans+=time(a,b,ans);
        }
        //cout<<" "<<ans<<endl;
    }
    cout<<ans;
    system("pause");
    return 0;
}