#include<bits/stdc++.h>
using namespace std;
struct node
{
    int y,re,l0,r1,sum;
};
vector<node>s;
bool cmp(node a,node b)
{
    return a.y<b.y;
}
bool cmp1(node a,node b){
    if(a.y==b.y){
        return a.sum<b.sum;
    }
    else return a.y<b.y;
}
int main()
{
    node x;
    int m=0;
    cin>>m;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x.y,&x.re);
        s.push_back(x);
    }
    sort(s.begin(),s.end(),cmp);

    s[0].l0=0;
    for(int i=1;i<m;i++){
       s[i].l0=s[i-1].l0+(s[i-1].re==0);
    }

    s[m-1].r1=(s[m-1].re==1);
    for(int i=m-2;i>=0;i--){
        s[i].r1=s[i+1].r1+s[i].re;
    }

    for(int i=0;i<m;i++){
        s[i].sum=s[i].r1+s[i].l0;
    }

    sort(s.begin(),s.end(),cmp1);

    int ans=s[0].y;
    int big=s[0].sum;

    for(int i=1;i<m;i++){
        if(s[i].y==s[i-1].y)continue;
        if(s[i].sum>=big){
            big=s[i].sum;
            ans=s[i].y;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}