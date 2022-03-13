#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        while(b>0)
        {
            ans+=(b%10)*a;
            b=b/10;
        } 
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}

