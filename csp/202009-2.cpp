#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,k,t,xl,xr,yd,yu;
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    int x,y;
    int cout=0,ans=0;
    for(int i=0;i<n;i++){
        int pe[1010]={0};
        cin>>x>>y;
        if(xl<=x&& yd<=y &&x<=xr &&y<=yu)pe[0]++;
        //printf("%d\n",pe[0]);
        for(int j=1;j<t;j++){
        int x1=0,y1=0;
        cin>>x1>>y1;
        if(xl<=x1&& yd<=y1 &&x1<=xr &&y1<=yu){
            pe[j]++;
            if(pe[j-1]>0)
            pe[j]+=pe[j-1];
            //printf("%d\n",pe[j]);
            } 
        }
        sort(pe,pe+t,cmp);
        //printf("\n%d\n",pe[0]);
       if(pe[0]>0){
       cout++;
       if(pe[0]>=k)
       ans++;
       }
   }
   printf("%d\n%d",cout,ans);
   system("pause");
    return 0;
}