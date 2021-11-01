#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int tmp=0,ans=0;
    while(cin>>a)
    {
        if(a==1)
        {
            ans++;
            tmp=0;
        }
        if(a==2)
        {
            if(tmp==0){
                ans+=2;
                tmp+=2;
            }
            else
            {
                ans+=2+tmp;
                tmp+=2;
            }
        }
        if(a==0)break;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}