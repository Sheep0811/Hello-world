#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, t;
	string a;
	cin >> n >> t;
	cin >> a;
	if (t == 2)
	{
		string ans;
		while (n--)
		{
			ll tmp = ans.size()/2;
			ans = ans.substr(0, tmp) + a[n] + ans.substr(tmp, ans.size());
		}
		cout << ans;
	}
	else if (t == 1)
	{
		string ans;
		while (n--)
		{
			ll tmp = 0;
			if (tmp % 2)
				tmp = n/ 2 + 1;
			else
				tmp = n / 2;
			ans+=a[tmp];
			a.erase(a.begin()+tmp);
		}
		cout<<ans;
	}
	system("pause");
	return 0;
}
