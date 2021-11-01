#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>

typedef struct
{
    int xds;  //�޵�ʿ
    int yr;   //Ұ��
    int cw;   //����λ�ã�0�Ұ���1��
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

void Ltableinit(Ltable **head)    //��ʼ���ڽӱ�
{
    *head=(Ltable *)malloc(sizeof (Ltable));  //��̬����ռ�
    (*head)->son=NULL;
    (*head)->bro=NULL;
    (*head)->par=NULL;
    (*head)->next=NULL;
}

void insertson(Ltable *head, DataType x)   //���ڽӱ��в�����ӽ��Ĳ���
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

void insertbro(Ltable *head,DataType x)     //���ڽӱ��в����ֵܽ��Ĳ��������е��ֵܽ�㶼ָ�������ұߵĽ��
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

int findfa(DataType x,int n)     //�����ڴ����޵�ʿ�԰�ȫ�ļ��������
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

int jiancha(DataType x,int n)     //��ȫ�Լ�⣬��鵱ǰ����£��޵�ʿ�Ƿ�ȫ
{
    if ((x.xds>=x.yr||x.xds==0)&&((n-x.xds)>=(n-x.yr)||x.xds==n)&&x.xds>=0&&x.xds<=n&&x.yr>=0&&x.yr<=n)
       return 1;
    else
       return 0;
}

void print(Ltable *q,Ltable *p)     //��ӡ��ȫ�ɺӵĹ���
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
    printf("�ɺӳɹ�!\n");
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
       printf("�޷��ɹ��ɺӣ��޵�ʿ������!\n");
    else
       printf("��%d�ֶɺӷ�ʽ��\n",count);
}

int main()
{
    Ltable *p;
    DataType tem;
    Ltableinit(&p);        //��ʼ���ڽӱ�;
    int n,c;
    while (1)
    {
       printf("�������޵�ʿ��Ұ�˵�����n:\n");
       scanf("%d",&n);
       if (n==0)
           break;
       printf("�����봬�����ɵ�����c:\n");
       scanf("%d",&c);
       tem.xds=n;
       tem.yr=n;
       tem.cw=1;
       insertson(p, tem);           //����ʼ״̬��Ϊͷ���ĺ��ӽ�㣻
       work(p,n,c);                 //���й��������
    }
    system("pause");
    return 0;
}


