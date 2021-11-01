#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct   //��ź͵÷� 
{
	int num;
	int grade;
}person;

person Person[512];

void set()//���������
{

	srand(time(NULL));//ͨ��ʱ���srand()�ṩһ������
	for(int i=0;i<512;i++)
	{
		Person[i].num=i+1;
		Person[i].grade=rand()%1000;
		//����rand()����������ṩ��srand()������ֵ����һ�������
		//��ΪҪ����0-999�����Զ�1000ȡ��
	}
	printf("��� �÷�\n");
	for(int i=0;i<512;i++)
	{
		printf("���:%4d ����:%5d\n",Person[i].num,Person[i].grade);
	}
}

void search1()//˳�����
{
	int j;
	person high1,high2;
	high1.grade=0,high2.grade=0;
	for(j=0;j<512;j++)//��һ��forѭ��Ѱ����߷�
	{
		if(Person[j].grade>high1.grade)
		{
			high1.grade=Person[j].grade;
			high1.num=Person[j].num;
		}
	}
	for(j=0;j<512;j++)//�ڶ���forѭ��Ѱ�Ҵθ߷�
	{
		if(Person[j].grade>high2.grade&&Person[j].num!=high1.num)
		{
			high2.grade=Person[j].grade;
			high2.num=Person[j].num;
		}
	}
	printf("��߷��ߵı��Ϊ%d������Ϊ%d\n�θ߷��ߵı��Ϊ%d������Ϊ%d\n",high1.num,high1.grade,high2.num,high2.grade);
}


person Tree[1024];

void search2()//�����������ҹ���
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
		}//����������бȽ�
		else
		{
			Tree[m/2].num=Tree[m].num;
			Tree[m/2].grade=Tree[m].grade;
		}//ѡ���ϴ�����浽Tree[m/2]��
		m=m-2;
	}
	n=Tree[1].num+511;//�Ӻ����ֵ�ȽϹ��ĵ�һ������ʼ
	person M;
	M.grade=0;
	for(i=0;i<9;i++)
	//��Ϊ512��2��9�η���������������й�9�αȽϣ�������9������ѡ���δ���
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
		}//��9�������ҵ����ֵ
		n=n/2;
	}
	printf("��߷��ߵı��Ϊ%d������Ϊ%d\n�θ߷��ߵı��Ϊ%d������Ϊ%d\n",Tree[1].num,Tree[1].grade,M.num,M.grade);
}


void maxHeap(int A[],int len,int i)
{
    int l,r,large,temp;
    l=2*i;     //������
    r=2*i+1;    //������
    large=i;     //�����
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
    //ѡ�����Ԫ��
    if(large!=i)//����н�������Ե�������������еݹ�
    {
        temp=A[large];  
        A[large]=A[i];
        A[i]=temp;
        maxHeap(A,len,large);
    }
}

void buildMaxHeap(int A[],int len)//�����󶥶�
{
    int i;
    for(i=len/2-1;i>=0;i--)//�����һ����Ҷ�ӽڵ㿪ʼ
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
	high1.grade=A[0];//�Ѷ�Ϊ���ֵ
	if(A[1]>A[2])//�ж϶Ѷ������������ĸ�����Ϊ�δ�ֵ
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
	printf("��߷��ߵı��Ϊ%d������Ϊ%d\n�θ߷��ߵı��Ϊ%d������Ϊ%d\n",high1.num,high1.grade,high2.num,high2.grade);
}

int main()
{
	set();
	printf("˳����ҷ���\n");
	search1();
	printf("���������ҷ���\n");
	search2();
	printf("ͨ���Ѳ��ң�\n");
	search3();
	system("pause");
	return 0;
}
