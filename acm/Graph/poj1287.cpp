#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm> 
using namespace std; 
const int N = 55;
int n, m, g[N][N], d[N], u, v, w; 
bool vis[N];
int prim() 
{
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	int ans = 0;
	for (int i = 0; i < n; i++) 
    {
		//�ҵ�һ������м��뼯��
		int t = -1;
		for (int j = 1; j <= n; j++) 
        {
			if (!vis[j] && (t == -1 || d[t] > d[j])) t = j;
		}	
		vis[t] = true; //���뼯��
		if (i) ans += d[t]; //�����ǵ�һ����	
		//�ı������㵽�ü��ϵľ��� 
		for (int j = 1; j <= n; j++) 
        d[j] = min(d[j], g[t][j]); 
	}
	return ans;
}
int main() 
{
	while (scanf("%d", &n), n) 
    {
		memset(g, 0x3f, sizeof(g));
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) 
        {
			scanf("%d%d%d", &u, &v, &w);
			g[u][v] = g[v][u] = min(g[u][v], w);
		}
		printf("%d\n", prim());
	}
    system("pause");
	return 0;
}