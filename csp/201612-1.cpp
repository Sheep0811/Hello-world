#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int bi=0,sm=0;
        for(int q=0;q<n;q++)
        {
            if(a[q]>a[i])bi++;
            if(a[q]<a[i])sm++;
        }
        if(bi==sm)
        {
            cout<<a[i]<<endl;
            flag=1;
            break;
        }
    } 
    if(flag==0)cout<<-1<<endl;
    system("pause");
    return 0;
}