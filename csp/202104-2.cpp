#include<bits/stdc++.h>
using namespace std;
int n,L,r,t,ans=0;
int a[610][610]={0};
long long sum[610][610];
int find(int xl,int xr,int yl,int yr)
{
    long long ans=0;
    int nums=(xr-xl+1)*(yr-yl+1);
    for(int i=xl;i<=xr;i++){
        ans+=sum[i][yr]-sum[i][yl-1];
    }
    if(ans>t*nums)return 0;
    else return 1;
}
int main()
{
    scanf("%d%d%d%d",&n,&L,&r,&t); 
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][0]);
        sum[i][0]=a[i][0];
        for(int j=1;j<n;j++){
        scanf("%d",&a[i][j]);
        sum[i][j]=sum[i][j-1]+a[i][j];
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            int xl,xr,yl,yr;
            xl=max(0,x-r);
            xr=min(n-1,x+r);
            yl=max(0,y-r);
            yr=min(n-1,y+r);
            ans+=find(xl,xr,yl,yr);
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}
