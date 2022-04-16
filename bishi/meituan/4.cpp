#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sb
{
	int l, r;
	friend bool operator<(const sb &a, const sb &b)
	{
		if (a.l != b.l)
			return a.l < b.l;
		return a.r < b.r;
	}
	friend bool operator>(const sb &a, const sb &b)
	{
		if (a.l != b.l)
			return a.l > b.l;
		return a.r > b.r;
	}
} a[31000];
void init(vector<pair<int, int>> &v, int m)
{
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i].l;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i].r;
	}
	sort(a, a + m);
	int i = 0;
	while (i < m)
	{
		int j = i;
		while (j + 1 < m && a[j + 1].l <= a[j].r)
			j++;
		a[i].r = a[j].r;
		v.push_back({a[i].l, a[i].r});
		i = j + 1;
	}
}
int main()
{
	int n, m1, m2;
	vector<pair<int, int>> v1, v2;
	cin >> n >> m1 >> m2;
	init(v1, m1);
	init(v2, m2);
	int p1 = 0, p2 = 0;
	int sz1 = v1.size();
	int sz2 = v2.size();
	int ans = 0;
	for (auto k : v1)
	{
		while (v2[p1 + 1].first <= k.first && p1 < sz2 - 1)
			p1++;
		while (v2[p2 + 1].first <= k.second && p2 < sz2 - 1)
			p2++;
		if (v2[p1].first > k.first)
			continue;
		for (int i = p1; i <= p2; ++i)
		{
			ans += min(k.second, v2[i].second) - max(k.first, v2[i].first) + 1;
		}
	}
	printf("%d", ans);
	system("pause");
	return 0;
}

