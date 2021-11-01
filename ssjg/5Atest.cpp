/*
�ɴ������������˶��ˣ�Ұ���������ߣ�
�Ұ����������ˣ�ͬʱ�޵�ʿ���������ߡ�
���޵�ʿ��Ұ���ϴ��󣬼�⵱������԰��������޵�ʿ�İ�ȫ״̬��
���޵�ʿ��ȫ���򽫴˽����뵽�ڽӱ��С�
*/
#include<stdio.h>	
#include<stdlib.h>
#include<malloc.h>
int n, c;
typedef struct        //��������
{
	int xds;     //���޵�ʿ����
	int ymr;     //��Ұ��������
	int bank;    //С��״̬��0���Ұ���1���󰶡�
}DataType;
DataType fa[10000];

typedef struct Node   //��
{
	int dest;
	struct Node *next;
}Edge;

typedef struct//������Ԫ��洢ͼ�Ľṹ״̬ 
{
	DataType data;
	int sorce;
	Edge *adj;
	int pre;
}AdjLHeight;
            
typedef struct     //�ڽӱ�
{
	AdjLHeight a[20000];
	int numOfVerts;    //������
	int numOfEdges;   //����
}AdjLGraph;

void AdjInitiate(AdjLGraph *G)      //�����ڽӱ�
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

void InsertVertex(AdjLGraph *G, int i, DataType vertex)  //����� 
{
	if (i >= 0 && i<20000)
	{
		G->a[i].data.xds = vertex.xds;
		G->a[i].data.ymr = vertex.ymr;
		G->a[i].data.bank = vertex.bank;
		G->numOfVerts++;
	}
	else printf("������Χ!\n");
}

void InsertEdge(AdjLGraph *G, int v1, int v2)//�����
{
	Edge *p;
	if (v1<0 || v1 >= G->numOfVerts || v2<0 || v2>G->numOfVerts)
	{
		printf("��������!");
		exit(0);
	}
	p = (Edge *)malloc(sizeof(Edge));
	p->dest = v2;
	p->next = G->a[v1].adj;
	G->a[v1].adj = p;
	G->numOfEdges++;
}

void AdjDestroy(AdjLGraph *G)      //�ڽӱ�����
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
}//���ڽӱ�洢ͼ�����ݽṹ
                           
int check(DataType x)//����Ƿ�ȫ
{
	if ((x.xds >= x.ymr || x.xds == 0)  
		&& ((n - x.xds) >= (n - x.ymr) || x.xds == n) 
		&& x.xds >= 0 && x.xds <= n
		&& x.ymr >= 0 && x.ymr <= n)
		return 1;     //��ȫ
	else
		return 0;
}

int findfa(DataType x)     //�����ڴ����޵�ʿ�԰�ȫ�����
{
	int i = 0, a, b, t = 0;    //�ӿ�ʼ���԰���״̬
	if (x.bank)
	{
		a = 0; b = c - a;//Ұ��������ʼ��Ϊ0������ȫΪ�޵�ʿ
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
	else       //���Ұ����󰶵�״̬
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
}//���ɼ����ڴ����ǰ�ȫ��״̬
                     
int print(AdjLGraph *p, int g)//�ú������ÿ�ζɺ�֮��������״̬�Ƿ��ǰ�ȫ�ģ������ȫ��ѽڵ���뵽�ڽӱ���
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
				printf(" �����������޵�ʿ%d��Ұ��%d�������������Ұ���\n ���������޵�ʿ%d��Ұ��%d��\n", 
					b[i].xds - b[i - 1].xds, b[i].ymr - b[i - 1].ymr, b[i - 1].xds, 
					b[i - 1].ymr);
			else
				printf(" �����������޵�ʿ%d��Ұ��%d�������Ұ������󰶡�\n ���������޵�ʿ%d��Ұ��%d��\n", 
					(b[i].xds - b[i - 1].xds)*(-1), (-1)*(b[i].ymr - b[i - 1].ymr), 
					b[i - 1].xds, b[i - 1].ymr);
		}
		else
			printf("\n");
	}
	
	return 1;
}
            
void work(AdjLGraph *p)//�������������
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
		printf("���ܶɺ�\n");
	else printf("�ɺӵķ����� %d ��\n",count);
}//�ù�������İ취���·��
                               
int main()
{
	AdjLGraph G;
	DataType first;
	printf("������Ұ�˺��޵�ʿ����N:");
	scanf("%d", &n);
	printf("�����봬����������C:");
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
