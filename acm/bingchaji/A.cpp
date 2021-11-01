#include<bits/stdc++.h>
using namespace std;

int fa[100010];
int n;

int find(int x)
{
    return x==fa[x] ? x :(fa[x]=find(fa[x]));
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    fa[i]=i;
}

int main()
{
  int m,a,b,c;
  scanf("%d%d",&n,&m);
  init(n);
  while(m)
  {
      scanf("%d%d%d",&a,&b,&c);
      if(a==1)
      fa[find(c)]=find(b);
      if(a==2)
      {
         if (find(b) == find(c)) 
         printf("Yes\n");
	     else printf("No\n");
      }
     m--; 
  } 
  system("pause");
  return 0;
}