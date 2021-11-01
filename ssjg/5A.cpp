#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>

typedef struct
{
    int xds;  //修道士
    int yr;   //野人
    int cw;   //船的位置，0右岸，1左岸
}DataType;

DataType fa[50000];

typedef struct node
{
    DataType data;
    struct node *son;
    struct node *bro;
    struct node *par;
    struct node *next;
}Ltable;

void Ltableinit(Ltable **head)    //初始化邻接表
{
    *head=(Ltable *)malloc(sizeof (Ltable));  //动态分配空间
    (*head)->son=NULL;
    (*head)->bro=NULL;
    (*head)->par=NULL;
    (*head)->next=NULL;
}

void insertson(Ltable *head, DataType x)   //在邻接表中插入儿子结点的操作
{
    Ltable *q,*s;
    q=(Ltable *)malloc(sizeof (Ltable));
    q->data=x;
    head->son=q;
    s=head;
    while (s->next!=NULL)
    s=s->next;
    q->par=head;
    q->son=NULL;
    q->bro=NULL;
    s->next=q;
    q->next=NULL;
}

void insertbro(Ltable *head,DataType x)     //在邻接表中插入兄弟结点的操作，所有的兄弟结点都指向他们右边的结点
{
    Ltable *q,*s;
    q=(Ltable *)malloc(sizeof (Ltable));
    s=head->son;
    q->data=x;
    while (s->bro!=NULL)
       s=s->bro;
    s->bro=q;
    s->next=q;
    q->next=NULL;
    q->bro=NULL;
    q->par=head;
    q->son=NULL;
}

int findfa(DataType x,int n)     //生成在船上修道士仍安全的几种情况；
{
    int i=0,a,b,t=0;
    if(x.cw)
    {
       a=0;b=n-a;
       while (a+b>=1)
           {
              t++;
              while (b>=0)
              {
                  fa[i].xds=a;
                  fa[i].yr=b;
                  i++;
                  a++;
                  b--;
              }
              a=0;
              b=n-a-t;
           }
    }
    else
    {
       a=1;b=0;t=0;
       while (a+b<=n)
       {
           t++;
           while (a>=0)
           {               
              fa[i].xds=a*(-1);
              fa[i].yr=b*(-1);
              i++;
              a--;
              b++;
           }
           a=fa[0].xds*(-1)+t;
           b=0;
       }
    }
    return i; 
}

int jiancha(DataType x,int n)     //安全性检测，检查当前情况下，修道士是否安全
{
    if ((x.xds>=x.yr||x.xds==0)&&((n-x.xds)>=(n-x.yr)||x.xds==n)&&x.xds>=0&&x.xds<=n&&x.yr>=0&&x.yr<=n)
       return 1;
    else
       return 0;
}

void print(Ltable *q,Ltable *p)     //打印安全渡河的过程
{
    DataType a[100];
    int i=1;
    a[0].cw=0;
    a[0].xds=0;
    a[0].yr=0;
    while (q!=p)
    {
       a[i++]=q->data;
       q=q->par;
    }
    while ((--i)>-1)    
    {
          printf("( %d %d %d )",a[i].xds,a[i].yr,a[i].cw);
          if (!(a[i].xds==0&&a[i].yr==0&&a[i].cw==0))
          {
              if (a[i].cw==1)
              printf(" --> ( %d %d ) --> ( %d %d 0 )\n",a[i].xds-a[i-1].xds,a[i].yr-a[i-1].yr,a[i-1].xds,a[i-1].yr);
              else 
              printf(" <-- ( %d %d ) <-- ( %d %d 1 )\n",(a[i].xds-a[i-1].xds)*(-1),(-1)*(a[i].yr-a[i-1].yr),a[i-1].xds,a[i-1].yr);}
          else printf("\n");
    }
    printf("渡河成功!\n");
}  
void work(Ltable *p,int n,int c) 
{ 
    Ltable *q,*t; 
    DataType tem; 
    int i,flag,flag1,g=0,j,count=0; 
    q=p->son; 
    while (q!=NULL) 
    { 
       flag=0; 
        j=findfa(q->data,c); 
        for (i=0;i<j;i++) 
       { 
           tem.xds=q->data.xds-fa[i].xds; 
           tem.yr=q->data.yr-fa[i].yr; 
           tem.cw=1-q->data.cw; 
           t=q; 
           if (jiancha (tem,n)) 
           { 
              flag1=1; 
                while (t!=p) 
              { 
           if(tem.xds==t->data.xds&&tem.yr==t->data.yr&&tem.cw==t->data.cw)
                  {
                     flag1=0;
                     break;               
                  }
                  t=t->par;
              }
                if(flag1==1)
              {
                  if (flag==0)
                  {
                     insertson(q, tem);
                     flag=1;
                  }
                  else
                     insertbro(q,tem);                         
                  if (tem.xds==0&&tem.yr==0&&tem.cw==0)
                  {
                     print(q,p);
                     count++;
                  }
              }         
           }
       } 
       q=q->next;
    } 
    if (count==0)
       printf("无法成功渡河，修道士好郁闷!\n");
    else
       printf("有%d种渡河方式。\n",count);
}

int main()
{
    Ltable *p;
    DataType tem;
    Ltableinit(&p);        //初始化邻接表;
    int n,c;
    while (1)
    {
       printf("请输入修道士与野人的人数n:\n");
       scanf("%d",&n);
       if (n==0)
           break;
       printf("请输入船可容纳的人数c:\n");
       scanf("%d",&c);
       tem.xds=n;
       tem.yr=n;
       tem.cw=1;
       insertson(p, tem);           //将初始状态作为头结点的孩子结点；
       work(p,n,c);                 //进行广度搜索；
    }
    system("pause");
    return 0;
}


