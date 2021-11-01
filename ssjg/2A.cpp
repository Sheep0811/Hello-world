#include<stdio.h>
#include<stdlib.h>

int n;
double sum=0;//�ܵĵȴ�ʱ��

struct task
{
    int st;//st����ʼʱ��
    int ct;//ct�������ʱ��
    int rt;//rt��ǰʱ�̶೤ʱ��֮����Կ�ʼִ������
    int idx;//idx���
}t[100],k;

int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

void rank1(int l,int r)//���ύ˳������
{
    for(int i=l;i<r;i++)
    { for(int j=i+1;j<=r;j++)
        {
            if(t[i].st>t[j].st)
            {
                k=t[j];
                t[j]=t[i];
                t[i]=k;
            }
        }
    }
}

void rank2(int l,int r)//���ʱ��
{
    for(int i=l;i<=r;i++)
    { 
            if(t[l].rt+t[l].ct>t[i].rt+t[i].ct||
               (t[l].rt+t[l].ct==t[i].rt+t[i].ct && t[l].rt>t[i].rt))
            {
                k=t[l];
                t[l]=t[i];
                t[i]=k;
            }
        }
    }


void work(int top,int tmp)//topΪ��δִ�е������еĵ�һ����tmpΪ��ǰʱ��
{
    if(top==n+1)//��������������˳�����
        return;
    rank2(top,n);//��ʱ����̵ķŵ�top
    tmp=max(tmp,t[top].st);//����Ϊ��ǰʱ��Ϊ����һ������ʼʱ���뵱ǰʱ������ֵ��
    //��Ϊ��һ������ʼʱ����ȴ�ʱ��
    printf("\n��%d�����������%d��\n",top,t[top].idx);
    printf("����Ŀ�ʼʱ��Ϊ��%d\n",tmp);
    printf("�ȴ�ʱ��Ϊ��%d\n",tmp);
    sum+=tmp;//ʹ��sum��¼�ȴ�ʱ��֮��
    tmp+=t[top].ct;//��ִ����һ������󣬸��µ�ǰʱ�䣬��Ϊ��ǰ�������ʱ�䡣
    printf("����Ľ���ʱ���ǣ�%d\n",tmp);
    for(int i=top+1;i<=n;i++)//����֮�������ĵȴ�ʱ��
        t[i].rt=max(0,t[i].st-tmp);
    work(top+1,tmp);//������һ����
}
int main()
{
    printf("��ѡ��ʹ�ó���\n");
    printf("1.���������ύ��ʱ������Ϊ������ͬʱ�ύ��\n");
    printf("2.������ͬʱ�ύ\n");
    int ord;
    scanf("%d",&ord);
    if(ord<1||ord>2)
    {
        printf("ѡ������\n");
        return 0;
    }
    else
    {
        printf("���������������:\n");
        scanf("%d",&n);
        sum=0;
        if(ord==1)
        {
            for(int i=1;i<=n;i++)
            {
                printf("��%d�ŵĳ���ʱ��Ϊ:",i);
                scanf("%d",&t[i].ct);
                t[i].st=t[i].rt=0;
                t[i].idx=i;
            }
            work(1,0);
            printf("ƽ���ȴ�ʱ��Ϊ:%lf",sum/n);
        }
        else
        {
            printf("��ѡ���ܣ�\n");
            printf("1.�����ύ˳��\n");
            printf("2.��̵ȴ�ʱ��\n");
            int orr;
            scanf("%d",&orr);
            for(int i=1;i<=n;i++)
            {
                printf("��%d������ʼ�����ʱ��Ϊ��\n",i);
                scanf("%d",&t[i].st);
                scanf("%d",&t[i].ct);
                t[i].rt=t[i].st;
                t[i].idx=i;
            }
            if(orr==1)
            {
                int tmp=0;//tmpΪ��ǰʱ��
                rank1(1,n);
                for(int i=1;i<=n;i++)
                {
                    tmp=max(tmp,t[i].st);//ÿ�θ���Ϊ��һ������ʼʱ���뵱ǰʱ���е����ֵ
                                        //��Ϊ��һ������Ŀ�ʼʱ����ȴ�ʱ�䡣
                    sum+=tmp;//ʹ��sum��¼�ȴ�ʱ��֮�͡�
                    printf("\n��%d�����������%d��\n",i,t[i].idx);
                    printf("����Ŀ�ʼʱ��Ϊ��%d\n",tmp);
                    printf("����ĵȴ�ʱ��Ϊ��%d\n",tmp);
                    tmp+=t[i].ct;//��ִ����һ������󣬸��µ�ǰʱ�䣬��Ϊ��ǰ�������ʱ�䡣
                    printf("����Ľ���ʱ��Ϊ:%d\n",tmp);
                }
                printf("ƽ���ȴ�ʱ��Ϊ:%lf\n",sum/n);//������ƽ���ȴ�ʱ��sum/n��nΪ�����������
            }
            else
            {
                int tmp=0;
                rank1(1,n);
                for(int i=1;i<=n;i++)
                {
                    tmp=max(tmp,t[i].st);
                    sum+=tmp;
                    tmp+=t[i].ct;
                }
                double pre=sum/n;
                sum=0;
                work(1,0);
                printf("\nƽ���ȴ�ʱ��Ϊ:%lf\n",sum/n);
                printf("��Ȱ�˳�����Լ��:%lf\n",pre-sum/n);
            }
        }
    }
    system("pause");
    return 0;
}
