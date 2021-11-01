#include<bits/stdc++.h>
using namespace std;
int have7(int x)
{
    while(x)
    {if(x%10==7)return 1;
    else x=x/10;}
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[4]={0};int nums=0;
    for(int i=1;i<=n;i++){
       if(i%7==0 || have7(i))
       {
           a[nums]++;
           n++;
       } 
           //cout<<a[nums];
       nums++;
       nums%=4;
    }
    for(int i=0;i<4;i++){
        cout<<a[i]<<endl;
    }
    system("pause");
    return 0;
}