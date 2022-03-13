#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string a;
    getline(cin,a);
    int n=a.size();
    string ans;
    sort()
    for(int i=0;i<n;++i)
    {
        if(a[i]=='<' ||a[i]=='=' || a[i]=='>')
        {
            ans+=" ";
            ans+=a[i];
            ans+=" ";
        }
        else if(a[i]!=' ')ans+=a[i];
    }
    cout<<ans;
    system("pause");
    return 0;
}