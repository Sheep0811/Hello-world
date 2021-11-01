#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,L,t;
    int a[101][2];
    cin>>n>>L>>t;
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=1;
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            a[j][0]+=a[j][1];
            if(a[j][0]==L){
                a[j][1]=0-a[j][1];
            }
            if(a[j][0]==0){
              a[j][1]=0-a[j][1];
            }
       }
        for(int q=0;q<n;q++){
            for(int j=q+1;j<n;j++){
            if(q!=j && a[q][0]==a[j][0])
            {
                a[q][1]=0-a[q][1];
                a[j][1]=0-a[j][1];
                break;
            }
            }
       } 
//    for(int i=0;i<n;i++){
//        cout<<a[i][0]<<" ";
//    }
//    cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<a[i][0]<<" ";
    }
    system("pause");
    return 0;
}