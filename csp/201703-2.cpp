#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
    int n,m; 
    scanf("%d%d",&n,&m);
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        int tmp=a[p-1];
        a[p-1]=a[p-1]+q;
        //cout<<a[p-1]<<endl;
        if(q>0)
        {
        for(int i=0;i<n;i++)
        {
            if(i!=p-1 && a[i]>tmp && a[i]<=a[p-1])a[i]--;
         //   cout<<a[i]<<" ";
        }
        }
        if(q<0)
        {
        for(int i=0;i<n;i++)
        {
            if(i!=p-1 && a[i]<tmp && a[i]>=a[p-1])a[i]++;
        }
        }
   }
   for(int i=0;i<n;i++)
   {
       for(int q=0;q<n;q++)
       {
        if(a[q]==i)
        {
         printf("%d ",q+1);
        // cout<<q+1<<" ";
        } 
       }
   }
   //cout<<endl;
    system("pause");
    return 0;
}