#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node
{
    int x, y;
};

bool cmp(node a, node b);

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
    {
        cout << "-1";
        return 0;
    }
    node set;
    set.x = 0;
    set.y = 0;
    vector<node> a(n, set);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x >> a[i].y;
    }
    vector<node> b(m, set);
    int ans=0;
    for (int i = 0; i < m; ++i)
    {
        int b1,b2;
        cin >> b1>> b2;
        for(auto &k : a)
        {
            if(k.x>b2 && k.y>b1)
            {
                ans++;
                k.x=k.y=0;
            }
        }
        
    } 
    else cout<<"-1"; 
    system("pause");
    return 0;
}

bool cmp(node a, node b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
