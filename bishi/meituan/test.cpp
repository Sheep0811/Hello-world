#include <bits/stdc++.h>
using namespace std;

struct SB
{
    int l, r;
    friend bool operator<(const SB &a, const SB &b)
    {
        if (a.l != b.l)
            return a.l < b.l;
        return a.r < b.r;
    }
    friend bool operator>(const SB &a, const SB &b)
    {
        if (a.l != b.l)
            return a.l > b.l;
        return a.r > b.r;
    }
} a[31000];
void init(vector<pair<int, int>> &v, int m)
{
    for (int i = 0; i < m; i++)
        cin >> a[i].l;
    for (int i = 0; i < m; i++)
        cin >> a[i].r;
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
    ios::sync_with_stdio(false);
    int n, m1, m2;
    vector<pair<int, int>> v1, v2;
    cin >> n >> m1 >> m2;

    init(v1, m1);
    init(v2, m2);

    /*    for (auto [l1,r1] : v1) {
            printf("(%d,%d) ",l1,r1);
        }
        puts("");
        for (auto [l1,r1] : v2) {
            printf("(%d,%d) ",l1,r1);
        }
        puts("");*/

    int p1 = 0, p2 = 0;
    int sz1 = v1.size();
    int sz2 = v2.size();
    int ans = 0;
    for (auto [l1, r1] : v1)
    {
        /*printf("for (%d,%d)\n",l1,r1);*/
        while (v2[p1 + 1].first <= l1 && p1 < sz2 - 1)
            p1++;
        while (v2[p2 + 1].first <= r1 && p2 < sz2 - 1)
            p2++;
        if (v2[p1].first > l1)
            continue;
        /*printf("{");*/
        for (int i = p1; i <= p2; i++)
        {
            /*printf("(%d,%d)",v2[i].first,v2[i].second);*/
            ans += min(r1, v2[i].second) - max(l1, v2[i].first) + 1;
        }
        /*printf("}\n");*/
    }
    printf("%d", ans);
    system("pause");
    return 0;
}