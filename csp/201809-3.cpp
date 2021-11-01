#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int count=0;
    int *a=new int[1000000];
    for(int i=0;i<n;i++){
        int a1,b1;
        cin>>a1>>b1;
        for(int j=a1;j<b1;j++){
            a[j]=1;
        }
    } 
    for(int i=0;i<n;i++){
        int a1,b1;
        cin>>a1>>b1;
        for(int j=a1;j<b1;j++){
            if(a[j]==1)count++;
        }
    }    
    cout<<count<<endl;
    system("pause");
    return 0;
}