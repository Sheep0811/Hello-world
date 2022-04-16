#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    queue<pair<int,int>>a;
    while(t--)
    {
        int p;
        cin>>p;
        if(p==1)
        {
            int x,y;
            cin>>x>>y;
            a.push({x,y});
        }
        else if(p==2)
        {
            if(a.size()!=0)
            {
                cout<<a.front().first<<" "<<a.front().second<<endl;
                a.pop();
            }
            else
            {
                cout<<"no reliquaries."<<endl;
            }
        }
    } 
    system("pause");
    return 0;
}