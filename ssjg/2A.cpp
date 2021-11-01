#include<stdio.h>
#include<stdlib.h>

int n;
double sum=0;//总的等待时间

struct task
{
    int st;//st任务开始时间
    int ct;//ct任务持续时间
    int rt;//rt当前时刻多长时间之后可以开始执行任务
    int idx;//idx序号
}t[100],k;

int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

void rank1(int l,int r)//按提交顺序排序
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

void rank2(int l,int r)//最短时间
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


void work(int top,int tmp)//top为还未执行的任务中的第一个，tmp为当前时间
{
    if(top==n+1)//所有任务完成则退出函数
        return;
    rank2(top,n);//将时间最短的放到top
    tmp=max(tmp,t[top].st);//更新为当前时间为：下一个任务开始时间与当前时间的最大值。
    //即为下一个任务开始时间与等待时间
    printf("\n第%d个任务序号是%d号\n",top,t[top].idx);
    printf("任务的开始时间为：%d\n",tmp);
    printf("等待时间为：%d\n",tmp);
    sum+=tmp;//使用sum记录等待时间之和
    tmp+=t[top].ct;//在执行完一个任务后，更新当前时间，即为当前任务结束时间。
    printf("任务的结束时间是：%d\n",tmp);
    for(int i=top+1;i<=n;i++)//更新之后的任务的等待时间
        t[i].rt=max(0,t[i].st-tmp);
    work(top+1,tmp);//进行下一任务
}
int main()
{
    printf("请选择使用场景\n");
    printf("1.忽略任务提交的时间差（即认为各任务同时提交）\n");
    printf("2.各任务不同时提交\n");
    int ord;
    scanf("%d",&ord);
    if(ord<1||ord>2)
    {
        printf("选项有误\n");
        return 0;
    }
    else
    {
        printf("请输入任务的数量:\n");
        scanf("%d",&n);
        sum=0;
        if(ord==1)
        {
            for(int i=1;i<=n;i++)
            {
                printf("第%d号的持续时间为:",i);
                scanf("%d",&t[i].ct);
                t[i].st=t[i].rt=0;
                t[i].idx=i;
            }
            work(1,0);
            printf("平均等待时间为:%lf",sum/n);
        }
        else
        {
            printf("请选择功能：\n");
            printf("1.按照提交顺序\n");
            printf("2.最短等待时间\n");
            int orr;
            scanf("%d",&orr);
            for(int i=1;i<=n;i++)
            {
                printf("第%d个任务开始与持续时间为：\n",i);
                scanf("%d",&t[i].st);
                scanf("%d",&t[i].ct);
                t[i].rt=t[i].st;
                t[i].idx=i;
            }
            if(orr==1)
            {
                int tmp=0;//tmp为当前时间
                rank1(1,n);
                for(int i=1;i<=n;i++)
                {
                    tmp=max(tmp,t[i].st);//每次更新为下一个任务开始时间与当前时间中的最大值
                                        //即为下一个任务的开始时间与等待时间。
                    sum+=tmp;//使用sum记录等待时间之和。
                    printf("\n第%d个任务序号是%d号\n",i,t[i].idx);
                    printf("任务的开始时间为：%d\n",tmp);
                    printf("任务的等待时间为：%d\n",tmp);
                    tmp+=t[i].ct;//在执行完一个任务后，更新当前时间，即为当前任务结束时间。
                    printf("任务的结束时间为:%d\n",tmp);
                }
                printf("平均等待时间为:%lf\n",sum/n);//最后输出平均等待时间sum/n（n为任务个数）。
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
                printf("\n平均等待时间为:%lf\n",sum/n);
                printf("相比按顺序处理节约了:%lf\n",pre-sum/n);
            }
        }
    }
    system("pause");
    return 0;
}
