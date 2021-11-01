#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int a[10010];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printf("%d ",(a[0]+a[1])/2);
    for(int i=1;i<n-1;i++){
        printf("%d ",(a[i]+a[i-1]+a[i+1])/3);
    }
    printf("%d ",(a[n-2]+a[n-1])/2);
        system("pause");
    return 0;
}