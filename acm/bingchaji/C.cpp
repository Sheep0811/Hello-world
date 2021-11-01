#include<bits/stdc++.h>
using namespace std;

char lake[1000010];

void dye(int x,int m)
{
    if(lake[x+1]=='O')
    {
        lake[x+1]='X';
        dye(x+1,m);
    }
     if(lake[x-1]=='O')
    {
        lake[x-1]='X';
        dye(x-1,m);
    }
     if(lake[x+m]=='O')
    {
        lake[x+m]='X';
        dye(x+m,m);
    }
     if(lake[x-m]=='O')
    {
        lake[x-m]='X';
        dye(x-m,m);
    }
}

int main()  
{
    int n,m,count;
    scanf("%d%d",&n,&m);

    for (int i=1; i<=n; i++)
    {
		scanf("%*c");
		for (int j=1; j<=m; j++)
        {
			scanf("%c",&lake[i*m + j]);
		}
	}
    for(int j=1;j<=n;j++)
    {
        if (lake[j]=='O')
        {
            lake[j]='X';
            dye(j,m);
        }
    }
    for(int j=n*(m-1)+1;j<=n*m;j++)
    {
        if (lake[j]=='O')
        {
            lake[j]='X';
            dye(j,m);
        }
    }
    for(int j=1;j<=n*m;j=j+m)
    {
        if (lake[j]=='O')
        {
            lake[j]='X';
            dye(j,m);
        }
    }
    for(int j=m;j<=n*m;j=j+m)
    {
        if (lake[j]=='O')
        {
            lake[j]='X';
            dye(j,m);
        }      
    }
    for(int i=1;i<=n*m;i++)
    {
        if(lake[i]=='O')
        count++;
    }
    cout << count;
    system("pause");
    return 0;
}