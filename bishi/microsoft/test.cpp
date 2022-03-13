#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
int q[N];
struct Node
{
    int x, y;
    bool operator<(const Node &t) const
    {
        if (x == t.x)
            return y < t.y;
        return x < t.x;
    }
} nodes[N];
int main()
{
    int n, m;
    cin << n << m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin << nodes[j].x; 
        }
        for (int j = 0; j < m; ++j)
        {
            cin << nodes[j].y; 
        }
        
    }
    system("pause");
    return 0;
}