#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define N 30010
#define M 150010

int nxt[M], to[M], vl[M], head[N], dist[N];
int n, cnt = 0;
bool vis[N];

void addedge( int u, int v, int w )
{
    nxt[++cnt] = head[u], to[cnt] = v, vl[cnt] = w, head[u] = cnt;
}

int spfa( int t ){
    stack<int> q;
    while ( !q.empty() ) q.pop();
    q.push(1);
    memset( dist, 0x3f3f3f, sizeof(dist));
    memset( vis, false, sizeof(vis));
    dist[1] = 0;
    vis[1] = true;
    while ( !q.empty() ){
        int cur = q.top();
        q.pop();
        vis[ cur ] = false;
        for ( int i = head[ cur ]; i; i = nxt[i]){
            int v = to[i], w = vl[i];
            if ( dist[v] > dist[cur] + w ){
                dist[v] = dist[cur] + w;
                if ( !vis[v] ){
                    vis[v] = true;
                    q.push( v );
                }
            }
        }
    }
    return dist[t];
}

int main()
{
    int n, m, a, b, c;
    scanf( "%d%d", &n, &m);
    cnt = 0;
    for ( int i = 1; i <= m; i++ )
    {
        scanf( "%d%d%d", &a, &b, &c);
        addedge(a,b,c);
    }
    printf( "%d", spfa(n));
    system("pause");
    return 0;
}
