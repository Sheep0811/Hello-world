#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[10010];
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    while(m--)next_permutation(a,a+n);
    for(int j=0;j<n-1;j++)
    printf("%d ",a[j]);
    cout<<a[n-1];
    system("pause");
    return 0;
}