#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[1010]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=a[n-1]-a[n-2];
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]<ans)ans=a[i+1]-a[i];
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}