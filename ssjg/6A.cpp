#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct   //编号和得分 
{
	int num;
	int grade;
}person;

person Person[512];

void set()//生成随机数
{

	srand(time(NULL));//通过时间给srand()提供一个种子
	for(int i=0;i<512;i++)
	{
		Person[i].num=i+1;
		Person[i].grade=rand()%1000;
		//调用rand()，它会根据提供给srand()的种子值返回一个随机数
		//因为要求在0-999内所以对1000取余
	}
	printf("编号 得分\n");
	for(int i=0;i<512;i++)
	{
		printf("编号:%4d 分数:%5d\n",Person[i].num,Person[i].grade);
	}
}

void search1()//顺序查找
{
	int j;
	person high1,high2;
	high1.grade=0,high2.grade=0;
	for(j=0;j<512;j++)//第一个for循环寻找最高分
	{
		if(Person[j].grade>high1.grade)
		{
			high1.grade=Person[j].grade;
			high1.num=Person[j].num;
		}
	}
	for(j=0;j<512;j++)//第二个for循环寻找次高分
	{
		if(Person[j].grade>high2.grade&&Person[j].num!=high1.num)
		{
			high2.grade=Person[j].grade;
			high2.num=Person[j].num;
		}
	}
	printf("最高分者的编号为%d，分数为%d\n次高分者的编号为%d，分数为%d\n",high1.num,high1.grade,high2.num,high2.grade);
}


person Tree[1024];

void search2()//锦标赛法查找过程
{
	int i,m=1023,n;

	for(i=512;i<=1023;i++)
	{
		Tree[i].num=Person[i-512].num;
		Tree[i].grade=Person[i-512].grade;
	}
	while(m!=1)                   
	{
		if(Tree[m-1].grade>=Tree[m].grade)
		{
			Tree[m/2].num=Tree[m-1].num;
			Tree[m/2].grade=Tree[m-1].grade;
		}//两两分组进行比较
		else
		{
			Tree[m/2].num=Tree[m].num;
			Tree[m/2].grade=Tree[m].grade;
		}//选出较大的数存到Tree[m/2]中
		m=m-2;
	}
	n=Tree[1].num+511;//从和最大值比较过的第一个数开始
	person M;
	M.grade=0;
	for(i=0;i<9;i++)
	//因为512是2的9次方，所以最大数进行过9次比较，故在这9个数中选出次大数
	{
		if(n%2)
		{
			if(Tree[n-1].grade>=M.grade)
			{
				M.num=Tree[n-1].num;
				M.grade=Tree[n-1].grade;
			}
		}
		else
		{
			if(Tree[n+1].grade>M.grade)
			{
				M.num=Tree[n+1].num;
				M.grade=Tree[n+1].grade;
			}
		}//在9个数中找到最大值
		n=n/2;
	}
	printf("最高分者的编号为%d，分数为%d\n次高分者的编号为%d，分数为%d\n",Tree[1].num,Tree[1].grade,M.num,M.grade);
}


void maxHeap(int A[],int len,int i)
{
    int l,r,large,temp;
    l=2*i;     //左子树
    r=2*i+1;    //右子树
    large=i;     //根结点
    if(l<len)
    {
        if(A[l]>A[i])
        {
            large=l;
        }
    }
    if(r<len)
    {
        if(A[r]>A[large])
        {
            large=r;
        }
    }
    //选出最大元素
    if(large!=i)//如果有交换，则对调整后的子树进行递归
    {
        temp=A[large];  
        A[large]=A[i];
        A[i]=temp;
        maxHeap(A,len,large);
    }
}

void buildMaxHeap(int A[],int len)//建立大顶堆
{
    int i;
    for(i=len/2-1;i>=0;i--)//从最后一个非叶子节点开始
        maxHeap(A,len,i);
}


void search3()
{
	int j,A[512];
	for(j=0;j<512;j++)
	{
		A[j]=Person[j].grade;
	}
	buildMaxHeap(A,512);
	person high1,high2;
	high1.grade=A[0];//堆顶为最大值
	if(A[1]>A[2])//判断堆顶的左右子树哪个更大即为次大值
		high2.grade=A[1];
	else
		high2.grade=A[2];
	for(int k=0;k<512;k++)
	{
		if(Person[k].grade==high1.grade)
		{	high1.num=Person[k].num;
			break;
		}
	}
	for(int k=0;k<512;k++)
	{
		if(Person[k].grade==high2.grade&&Person[k].num!=high1.num)
		{	high2.num=Person[k].num;
			break;
		}
	}
	printf("最高分者的编号为%d，分数为%d\n次高分者的编号为%d，分数为%d\n",high1.num,high1.grade,high2.num,high2.grade);
}

int main()
{
	set();
	printf("顺序查找法：\n");
	search1();
	printf("锦标赛查找法：\n");
	search2();
	printf("通过堆查找：\n");
	search3();
	system("pause");
	return 0;
}
