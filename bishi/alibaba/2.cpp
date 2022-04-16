#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int mi[1100][1100],mj[1100][1100],mx[1100][1100];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&mx[i][j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            mi[i][j]=(mx[i][j]==1)+mi[i-1][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            mj[i][j]=(mx[i][j]==1)+mj[i][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(mx[i][j]==0)
            {
                ans+=(mi[i][j]-mi[0][j]>0);
                ans+=(mi[n][j]-mi[i][j]>0);
                ans+=(mj[i][j]-mj[i][0]>0);
                ans+=(mj[i][m]-mj[i][j]>0);
            }
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}