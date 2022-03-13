#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a,b;
bool is(string x);

int main()
{
    ll c,d,e;
    cin>>a>>b;
    cin>>c>>d>>e;
    while (true)
    {
        e++;
        if(e>b)
        {
            e=1;
            d++;
            if(d>a)
            {
                d=1;
                c++;
            }
            string tmp=to_string(c)+to_string(d)+to_string(e);
            if(is(tmp))
            {
                cout<<c<<" "<<d<<" "<<e;
                break;
            }
        }
        else
        {
            string tmp=to_string(c)+to_string(d)+to_string(e);
            if(is(tmp))
            {
                cout<<c<<" "<<d<<" "<<e;
                break;
            }
        }
    }
    system("pause");
    return 0;
}

bool is(string x)
{
    string revtmp=x;
    reverse(revtmp.begin(),revtmp.end());
    if(revtmp==x)return true;
    return false;
}
