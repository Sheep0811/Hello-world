#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	//ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> a(n,0);
	vector<ll>b(n,0);
	cin>>a[0];
	for(ll i=1;i<n;++i)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	cin>>b[0];
	for(ll i=1;i<n;++i)
	{
		cin>>b[i];
		b[i]+=b[i-1];
	}
	ll m;
	cin>>m;
	vector<ll>c(m,0);
	vector<ll>d(m,0);
	for(ll i=0;i<m;++i)
	cin>>c[i];
	for(ll i=0;i<m;++i)
	cin>>d[i];
	for(ll i=0;i<n;++i)
	{
		ll tmp=a[i];
		ll cut=0;
		for(ll j=m-1;j>=0;--j)
		{
			if(c[j]<=tmp)
			{
				cut=d[j];
				break;
			}
		}
		if(tmp-cut>b[i])
		cout<<"Z";
		else if(tmp-cut==b[i])
		cout<<"B";
		else 
		cout<<"M";
	}
	system("pause");
	return 0;
}
