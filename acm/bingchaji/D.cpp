#include<bits/stdc++.h>
using namespace std;
#define N 305
int f[N][N],s[N],n,m;
vector<int>son[N];
inline void dp(int x)
{
	f[x][0]=0;
	for(int i=0;i<son[x].size();i++)
	{
		int y=son[x][i];dp(y);for(int t=m;t>=0;t--)for(int j=t;j>=0;j--)
		if(t-j>=0)f[x][t]=max(f[x][t],f[x][t-j]+f[y][j]);
	}
	if(x!=0)
	for(int t=m;t>=0;t--)f[x][t]=f[x][t-1]+s[x];
} 
 int main()
 {
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;i++)
 	{
 		int x;
 		scanf("%d%d",&x,&s[i]);
 		son[x].push_back(i);
	 }
	 memset(f,-1*0x3f,sizeof(f));
	 dp(0);
	 printf("%d",f[0][m]);
     system("pause");
	 return 0;
 } 