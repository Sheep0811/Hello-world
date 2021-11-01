#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int e=0,d=0,t=0;
    int dr[n]={0};
    for(int i=0;i<n;i++){
        int m=0;int nums=0;
        cin>>m;
        cin>>nums;
        int flag=0;
       for(int j=1;j<m;j++){
           int a;
           cin>>a;
           
           if(a<=0){
           nums+=a; 
           }
           if(a>0){
               if(a!=nums){
                   nums=a;
                   dr[i]=1;
                   flag=1;
               }
           }
      } 
      if(flag==1)d++;           
      t+=nums;
    }
    for(int i=0;i<n;i++){
        if(dr[i]!=0 && dr[(i-1+n)%n]!=0 && dr[(i+1+n)%n]!=0)e++;
    }
    cout<<t<<" "<<d<<" "<<e<<endl;
    system("pause");
    return 0;
}
