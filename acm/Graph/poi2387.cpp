#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e5+7;
const int maxm=1e6+7;
const int INF=0x3f3f3f3f;
int m,n,d[maxn],head[maxn],tol,u,v,w;

struct qnode
{
    int v;
    int c;
    qnode(int a,int b)
    {
        v=a;
        c=b;
    }
    bool operator<(const qnode &r)const{
        return c>r.c;
    }
};

struct node
{
    int to,next,w;
}edge[maxm];

bool vis[maxn];

void add(int u,int v,int w)
{
    edge[tol].to=v;
    edge[tol].next=head[u];
    edge[tol].w=w;
    head[u]=tol++; 
}

void init()
{
    tol=1;
    memset(head,-1,sizeof head);
}

int dijkstra(int st)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=INF,vis[i]=false;
    }
   d[st]=0;
   priority_queue<qnode> q;
   q.push(qnode(st,d[st]));
   while(!q.empty())
   {
       qnode tmp=q.top();
       q.pop();
       int u=tmp.v;
       if(vis[u])continue;
       for(int i=head[u];i!=-1;i=edge[i].next)//直到不是链表尽头
       {
           int v=edge[i].to;
           int w=edge[i].w;
           if(!vis[v]&&d[v]>d[u]+w)
           {
               d[v]=d[u]+w;
               q.push(qnode(v,d[v]));
           }
       }
       vis[u]=true;//已经遍历过
   }
return d[n];
}


int main()
{
    init();

    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    printf("%d\n",dijkstra(1));
    system("pause");
    return 0;
}
