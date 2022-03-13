#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    string a, ans;
    cin >> a;
    int n = a.size();
    int tmp = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            tmp++;
        }
        else
        {
            ans += to_string(tmp) + a[i - 1];
            tmp = 1;
        }
    }
    ans += to_string(tmp) + a[n-1];
    cout<<ans;
    system("pause");
    return 0;
}