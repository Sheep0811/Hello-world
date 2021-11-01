#include<bits/stdc++.h>
using namespace std;
bool check(int x,int y) 
{
    if(x%y==0 || x%10==y)
    return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int ans[1001]={0};
    int num=0;
    int count=1;
    int a=n;
    while(a!=1)
    {
        if(ans[num]==0)
        {
            if (check(count,k)){
                ans[num]=1;
                a--;
                //cout<<num<<endl;
            }
        num++;
        num=num%n;
        count++;
        }
        else{
        num++;
        num=num%n;
        }
   }
    for(int i=0;i<n;i++){
        if(ans[i]==0)
        cout<<i+1<<endl;
    }
    system("pause");
    return 0;
}