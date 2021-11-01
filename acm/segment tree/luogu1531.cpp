#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int u,v,val;
}t[4000001];
int a[200001];
int tot = 0;
void made(int kk,int x,int y)//建树
{
	tot = max(tot,kk);
	if(x == y)
	{
		t[kk].u = x;
		t[kk].v = y;
		t[kk].val = a[x];
		return;	
	}
	int mid = (x+y)/2;
	made(kk*2,x,mid);
	made(kk*2+1,mid+1,y);
	t[kk].u = x;
	t[kk].v = y;
	t[kk].val = max(t[kk*2].val,t[kk*2+1].val);
	return;
}
int ans(int x,int y,int u)//询问
{
	if(y >= t[u].v && x <= t[u].u) return t[u].val;
	if(t[u].u > y||t[u].v < x) return 0;//优化，不然询问nlogn
	return max(ans(x,y,u*2),ans(x,y,u*2+1));
}
void change(int u,int k,int b)//修改
{
	if(k == t[u].u && k == t[u].v)
	{
		t[u].val = max(t[u].val,b);
		return;
	}
	change(u*2+(k > t[u*2].v),k,b);
	t[u].val = max(t[u*2].val,t[u*2+1].val); 
	return;
}
int main()
{
	int n,m;
    while(~scanf("%d%d",&n,&m))
	{
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}

	made(1,1,n);

	for(int i = 1;i <= m;i++)
	{
		char C;
		cin >> C;
		if(C == 'Q')
		{
			int from,to;
			scanf("%d%d",&from,&to);
			printf("%d\n",ans(from,to,1));
		}
		else if(C == 'U')
		{
			int k,b;
			scanf("%d%d",&k,&b);
			change(1,k,b);
		}
	}
	}
	return 0;
}