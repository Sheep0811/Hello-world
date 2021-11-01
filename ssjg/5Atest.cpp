/*
渡船规则：左岸优先运多人，野人优先运走；
右岸优先运少人，同时修道士，优先运走。
让修道士跟野人上船后，检测当船到达对岸后，两岸修道士的安全状态，
若修道士安全，则将此结点加入到邻接表中。
*/
#include<stdio.h>	
#include<stdlib.h>
#include<malloc.h>
int n, c;
typedef struct        //数据类型
{
	int xds;     //左岸修道士人数
	int ymr;     //左岸野蛮人人数
	int bank;    //小船状态，0在右岸，1在左岸。
}DataType;
DataType fa[10000];

typedef struct Node   //边
{
	int dest;
	struct Node *next;
}Edge;

typedef struct//建立三元表存储图的结构状态 
{
	DataType data;
	int sorce;
	Edge *adj;
	int pre;
}AdjLHeight;
            
typedef struct     //邻接表
{
	AdjLHeight a[20000];
	int numOfVerts;    //顶点数
	int numOfEdges;   //边数
}AdjLGraph;

void AdjInitiate(AdjLGraph *G)      //创建邻接表
{
	int i;
	G->numOfEdges = 0;
	G->numOfVerts = 0;
	for (i = 0; i<20000; i++)
	{
		G->a[i].sorce = i;
		G->a[i].adj = NULL;
		G->a[i].data.bank = -1;
		G->a[i].pre = -1;
	}
}

void InsertVertex(AdjLGraph *G, int i, DataType vertex)  //插入点 
{
	if (i >= 0 && i<20000)
	{
		G->a[i].data.xds = vertex.xds;
		G->a[i].data.ymr = vertex.ymr;
		G->a[i].data.bank = vertex.bank;
		G->numOfVerts++;
	}
	else printf("超出范围!\n");
}

void InsertEdge(AdjLGraph *G, int v1, int v2)//插入边
{
	Edge *p;
	if (v1<0 || v1 >= G->numOfVerts || v2<0 || v2>G->numOfVerts)
	{
		printf("参数出错!");
		exit(0);
	}
	p = (Edge *)malloc(sizeof(Edge));
	p->dest = v2;
	p->next = G->a[v1].adj;
	G->a[v1].adj = p;
	G->numOfEdges++;
}

void AdjDestroy(AdjLGraph *G)      //邻接表销毁
{
	int i;
	Edge *p, *q;
	for (i = 0; i<G->numOfVerts; i++)
	{
		p = G->a[i].adj;
		while (p != NULL)
		{
			q = p->next;
			free(p);
			p = q;
		}
	}
}//用邻接表存储图的数据结构
                           
int check(DataType x)//检测是否安全
{
	if ((x.xds >= x.ymr || x.xds == 0)  
		&& ((n - x.xds) >= (n - x.ymr) || x.xds == n) 
		&& x.xds >= 0 && x.xds <= n
		&& x.ymr >= 0 && x.ymr <= n)
		return 1;     //安全
	else
		return 0;
}

int findfa(DataType x)     //生成在船上修道士仍安全的情况
{
	int i = 0, a, b, t = 0;    //从开始到对岸的状态
	if (x.bank)
	{
		a = 0; b = c - a;//野人数量初始化为0，船上全为修道士
		while (a + b >= 1)
		{
			t++;
			while (b >= 0)
			{
				fa[i].xds = a;
				fa[i].ymr = b;
				i++;
				a++;
				b--;
			}
			a = 0;
			b = c - a - t;
		}
	}
	else       //从右岸到左岸的状态
	{
		a = 1; b = 0; t = 0;
		while (a + b <= c)
		{
			t++;
			while (a >= 0)
			{
				fa[i].xds = a*(-1);
				fa[i].ymr = b*(-1);
				i++;
				a--;
				b++;
			}
			a = fa[0].xds*(-1) + t;
			b = 0;
		}
	}
	return i;
}//生成几种在船上是安全的状态
                     
int print(AdjLGraph *p, int g)//用函数检测每次渡河之后两岸的状态是否是安全的，如果安全则把节点加入到邻接表中
{
	DataType b[10000];
	int i = 0;
	while (g != -1)
	{
		b[i++] = p->a[g].data;
		g = p->a[g].pre;
	}

	while ((--i)>-1)
	{
		if (!(b[i].xds == 0 && b[i].ymr == 0 && b[i].bank == 0))
		{
			if (b[i].bank == 1)
				printf(" 船上人数：修道士%d，野人%d，船从左岸走向右岸。\n 左岸人数：修道士%d，野人%d。\n", 
					b[i].xds - b[i - 1].xds, b[i].ymr - b[i - 1].ymr, b[i - 1].xds, 
					b[i - 1].ymr);
			else
				printf(" 船上人数：修道士%d，野人%d，船从右岸走向左岸。\n 左岸人数：修道士%d，野人%d。\n", 
					(b[i].xds - b[i - 1].xds)*(-1), (-1)*(b[i].ymr - b[i - 1].ymr), 
					b[i - 1].xds, b[i - 1].ymr);
		}
		else
			printf("\n");
	}
	
	return 1;
}
            
void work(AdjLGraph *p)//广度搜索建立表
{
	DataType tem;
	int i, flag1, g = 0, j, count = 0, k = 0, t;
	while (p->a[k].data.bank != -1)
	{
		j = findfa(p->a[k].data);
		for (i = 0; i<j; i++)
		{
			tem.xds = p->a[k].data.xds - fa[i].xds;
			tem.ymr = p->a[k].data.ymr - fa[i].ymr;
			tem.bank = 1 - p->a[k].data.bank;
			if (check(tem))
			{
				flag1 = 1;
				t = k;
				while (t != -1)
				{
					if (tem.xds == p->a[t].data.xds&&tem.ymr == p->a[t].data.ymr&&tem.bank 
						== p->a[t].data.bank)
					{
						flag1 = 0;
						break;
					}
					t--;
				}

				if (flag1 == 1)
				{
					g++;
					p->a[g].pre = k;
					InsertVertex(p, g, tem);
					InsertEdge(p, k, g);
					if (tem.xds == 0 && tem.ymr == 0 && tem.bank == 0)
					{
						count++;
						print(p, g);
					}
				}
			}
		}
		k++;
	}
	if (count == 0)
		printf("不能渡河\n");
	else printf("渡河的方法有 %d 种\n",count);
}//用广度搜索的办法输出路径
                               
int main()
{
	AdjLGraph G;
	DataType first;
	printf("请输入野人和修道士人数N:");
	scanf("%d", &n);
	printf("请输入船可容纳人数C:");
	scanf("%d", &c);
	AdjInitiate(&G);
	first.xds = n;
	first.ymr = n;
	first.bank = 1;
	InsertVertex(&G, 0, first);
	work(&G);
	AdjDestroy(&G);
	system("pause");
	return 0;
}
