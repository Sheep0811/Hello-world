#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000
#define MAXM 1000
int mp1[MAXN][MAXM];
int mp2[MAXN][MAXM];
bool inq[MAXN][MAXM];
queue<pair<int, int>> q;
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
int main()
{
	int n, m;
	cin >> n >> m;
	int sr, sc, er, ec;
	cin >> sr >> sc >> er >> ec;
	mp1[sr][sc] = 1;
	int n_pool, tr, tc;
	cin >> n_pool;
	while (n_pool--)
	{
		cin >> tr >> tc;
		mp1[tr][tc] = -2;
	}
	q.push({sr, sc});
	inq[sr][sc] = true;
	while (!q.empty())
	{
		auto [cr, cc] = q.front();
		q.pop();
		inq[cr][cc] = false;
		for (int i = 0; i < 4; i++)
		{
			tr = cr + dr[i];
			tc = cc + dc[i];
			if (tr < 0 || tr >= n || tc < 0 || tc >= m)
				continue;
			if (mp1[tr][tc] == -2)
				continue;
			if (mp1[tr][tc] == 0 || mp1[tr][tc] - 1 > mp1[cr][cc])
			{
				mp1[tr][tc] = mp1[cr][cc] + 1;
				if (!inq[tr][tc] && (!(tr == er && tc == ec)))
				{
					inq[tr][tc] = true;
					q.push({tr, tc});
				}
			}
		}
	}
	inq[er][ec] = true;
	mp2[er][ec] = 1;
	q.push({er, ec});
	while (!q.empty())
	{
		auto [cr, cc] = q.front();
		q.pop();
		inq[cr][cc] = false;
		for (int i = 0; i < 4; i++)
		{
			tr = cr + dr[i];
			tc = cc + dc[i];
			if (tr < 0 || tr >= n || tc < 0 || tc >= m)
				continue;
			if (mp1[tr][tc] == -2)
				continue;
			if (mp1[tr][tc] == mp1[cr][cc] - 1)
			{
				mp2[tr][tc] += mp2[cr][cc];
				if (!inq[tr][tc] && (!(tr == sr && tc == sc)))
				{
					inq[tr][tc] = true;
					q.push({tr, tc});
				}
			}
		}
	}
	cout << mp2[sr][sc] << " " << mp1[er][ec] - 1;
	system("pause");
	return 0;
}
