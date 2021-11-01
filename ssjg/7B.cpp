#include<stdio.h>
#include<stdlib.h>
int n;  //����

typedef struct {
		int score[100][2];
		int spouse = 0;   //����ż 

}people;

people boy[100],girl[100];

void Heap_boy(int i,int j,int n) //�����󶥶�
{
	if( 2*j<=n && boy[i].score[2*j][1]>boy[i].score[j][1] )//���
	 {
		int temp1=boy[i].score[j][0];
		int temp2=boy[i].score[j][1];
		boy[i].score[j][0] = boy[i].score[2*j][0];
		boy[i].score[j][1] = boy[i].score[2*j][1];
		boy[i].score[2*j][0] = temp1;
		boy[i].score[2*j][1] = temp2;
		Heap_boy(i,2*j,n);
	}
	if(2*j+1<=n && boy[i].score[2*j+1][1]>boy[i].score[j][1]) 
	{
		int temp1=boy[i].score[j][0];
		int temp2=boy[i].score[j][1];
		boy[i].score[j][0] = boy[i].score[2*j+1][0];
		boy[i].score[j][1] = boy[i].score[2*j+1][1];
		boy[i].score[2*j+1][0] = temp1;
		boy[i].score[2*j+1][1] = temp2;
		Heap_boy(i,2*j+1,n);
	}
}
void maxHeap_boy() //�󶥶�
{
	for(int i = 1 ; i <= n ; ++i)
		for(int j = n ; j > 0 ; --j)
			Heap_boy(i,j,n);
}

void adjust_boy(int i)
{
	boy[i].score[1][0]= boy[i].score[n][0];
	boy[i].score[1][1]= boy[i].score[n][1];
	boy[i].score[n][0] = 0;
	boy[i].score[n][1] = 0; 
	Heap_boy(i,1,n);
}

int Gale_Shapley() 
{
	while(1) 
	{
		int flag = 0;
		for(int i = 1 ; i <= n ; ++i)
		 {
			if(boy[i].spouse == 0 && boy[i].score[1][0] != 0) //��������ż
			{
				if(girl[boy[i].score[1][0]].spouse == 0)//���������ϲ����Ů������ż���������
				{
					girl[boy[i].score[1][0]].spouse = i;
					boy[i].spouse = boy[i].score[1][0];
					adjust_boy(i);
				} 
				else 
				{
					if(girl[boy[i].score[1][0]].score[girl[boy[i].score[1][0]].spouse][1]< girl[boy[i].score[1][0]].score[i][1]) 
					//���Ů������ż����ƫ�õ�ǰ���������������
				    {
						boy[girl[boy[i].score[1][0]].spouse].spouse = 0;
						girl[boy[i].score[1][0]].spouse = i;
						boy[i].spouse = boy[i].score[1][0];
						adjust_boy(i);
					}
					else
					{
						adjust_boy(i);
					}
				}
				flag = 1;	
			}
		}
		if(!flag) break;//���Ӽ��϶�����ż�����˳�
	}
}


int main() {
	printf("��ӭ�����������Լ������\n������Ů�α�����Ϊ:");
	scanf("%d",&n);  //����
	printf("\n"); 
	for(int i = 1 ; i <= n ; ++i) {   //������
		printf("���Ϊ %d ���мα��� %d λŮ�α����Ķ�ָ���ֱ�Ϊ:\n",i,n);
		for(int j = 1 ; j <= n ; ++j) 
		{
			boy[i].score[j][0] = j;
			scanf("%d",&boy[i].score[j][1]);
		}
	}
	printf("\n"); 
	for(int i = 1 ; i <= n ; ++i) //����Ů
	{  
	    printf("���Ϊ %d ��Ů�α��� %d λ�мα����Ķ�ָ���ֱ�Ϊ:\n",i,n);
		for(int j = 1 ; j <= n ; ++j) 
		{
			girl[i].score[j][0] = j;
			scanf("%d",&girl[i].score[j][1]);
		}
	}

	maxHeap_boy();
	Gale_Shapley();

	//printf("\nף��һ�Զ������ܹ�һ�����ء�һ��ƽ�����򳪸��͡���ͷ����\n\n�����ׯ�ϵ���̨��������:\n\n"); 
	printf("�����ȶ�����ƥ���㷨:\n\n");
	for(int i = 1 ; i <= n ; ++i) 
	{
		printf("ǣ�ֳɹ�����Ů�α�Ϊ���мα�:%d �� Ů�α�:%d\n\n",i,boy[i].spouse);
	}
    system("pause");
    return 0;
}