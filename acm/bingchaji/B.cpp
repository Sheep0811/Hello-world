#include<bits/stdc++.h>
using namespace std;

int fa[100010];
int Rank[100010];
int n;

int find(int x)
{
	if (x == fa[x])
		return x;
	else {
        Rank[x] = (Rank[x] + Rank[fa[x]]) % 3;
		return fa[x] = find(fa[x]);
	}
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        Rank[i]=0;
    }
}

void Union(int x, int y, int d)
{
	int xRoot = find(x);
	int yRoot = find(y);
	fa[xRoot] = yRoot;
	Rank[xRoot] = (Rank[y] - Rank[x] + 3 + d) % 3;
}

int main()
{
	int m, a,b,c, bRoot, cRoot;
	scanf("%d%d", &n, &m);
    init(n);
	while (m--) 
    {
		scanf("%d%d%d", &a, &b, &c);
        bRoot = find(b);
		cRoot = find(c);
        if(a==1)
        {
           Union(c,b,1);
        }
        else if(a==2)
        {
            if(bRoot==cRoot)
            {
            if ((Rank[b] - Rank[c] + 3) % 3 == 0)
            cout<<"Tie"<<endl;
            else if ((Rank[b] - Rank[c] + 3) % 3 == 2)
            cout<<"Win"<<endl;
            else if ((Rank[b] - Rank[c] + 3) % 3 == 1)
            cout<<"Loss"<<endl;
            }
            else cout<<"Unknow"<<endl;
        }
    }
    system("pause");
	return 0;
}