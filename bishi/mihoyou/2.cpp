#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            a+=to_string(tmp);
        }
        int i;
        for(i=0;i<n;++i)
        {
            char tmp;
            cin>>tmp;
            if(tmp==a[0])break;
        }
        if(i>n/2)
        cout<<n-i<<endl;
        else
        cout<<i;
    }
    system("pause");
    return 0;
}