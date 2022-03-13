#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int flag=1;
        for(int i=n;i<=m;++i)
        {
            
            int k=i;
            ll tmp=0;
            while(k>0)
            {
                tmp+=(k%10)*(k%10)*(k%10);
                k/=10;
            }
            if(tmp==i)
            {
                cout<<i<<" ";
                flag=0;
            }
        }
        if(flag)cout<<"no";
        cout<<endl;
    }

    system("pause");
    return 0;
}