#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string a,b;
	cin>>a>>b;
	int n=a.size(),m=b.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i]==b[j])
			dp[i+1][j+1]=dp[i][j]+1;
			else
			dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
		}
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int x=n,y=m;
	string ans;
	while(dp[x][y]>0)
	{
		if(dp[x-1][y]==dp[x][y])
		{
			x--;
			continue;
		}
		if(dp[x][y-1]==dp[x][y])
		{
			y--;
			continue;
		}
		if(dp[x][y]==dp[x-1][y-1]+1)
		{
			ans+=a[x-1];
			x--;y--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
	system("pause");
	return 0;
}
